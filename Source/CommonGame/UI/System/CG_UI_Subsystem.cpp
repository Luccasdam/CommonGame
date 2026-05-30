// Copyright Luccas de Avila Machado. All rights reserved.


#include "CG_UI_Subsystem.h"
#include "Engine/AssetManager.h"
#include "GameplayTagContainer.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "UI/Widgets/CG_UI_W_RootLayout.h"


UCG_UI_Subsystem* UCG_UI_Subsystem::Get(const UObject* WorldContextObject)
{
	if (GEngine)
	{
		const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);
		
		return UGameInstance::GetSubsystem<UCG_UI_Subsystem>(World->GetGameInstance());
	}
	
	return nullptr;
}

bool UCG_UI_Subsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance())
	{
		TArray<UClass*> FoundClasses;
		GetDerivedClasses(GetClass(), FoundClasses);
		
		return FoundClasses.IsEmpty();
	}
	
	return false;
}

void UCG_UI_Subsystem::RegisterRootLayoutWidget(UCG_UI_W_RootLayout* InRootLayoutWidget)
{
	checkf(InRootLayoutWidget, TEXT("Insert a valid Root Layout Widget."))
	RootLayoutWidget = InRootLayoutWidget;
}


void UCG_UI_Subsystem::PushWidgetToLayerStackAsync(const FGameplayTag& InLayerTag, TSoftClassPtr<UCG_UI_W_ActivatableWidget> InWidgetClass, TFunction<void(EAsyncWidgetPushState, UCG_UI_W_ActivatableWidget*)> AsyncPushCallback) const
{
	checkf(InLayerTag.IsValid(), TEXT("Insert a valid StackTag"))
	checkf(!InWidgetClass.IsNull(), TEXT("Insert a Valid WidgetClass"))
	
	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		InWidgetClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this, InLayerTag, InWidgetClass, AsyncPushCallback]()
			{
				UClass* LoadedClass = InWidgetClass.Get();
				check(LoadedClass)
				
				check(RootLayoutWidget)
				UCommonActivatableWidgetContainerBase* Stack = RootLayoutWidget->FindWidgetStackByLayerTag(InLayerTag);
				UCG_UI_W_ActivatableWidget* AddedWidget = Stack->AddWidget<UCG_UI_W_ActivatableWidget>(
					LoadedClass,
					[AsyncPushCallback](UCG_UI_W_ActivatableWidget& WidgetInstance)
					{
						AsyncPushCallback(EAsyncWidgetPushState::OnCreatedBeforePush, &WidgetInstance);
					}
				);
				
				AsyncPushCallback(EAsyncWidgetPushState::AfterPush, AddedWidget);
			}
		)
	);
}
