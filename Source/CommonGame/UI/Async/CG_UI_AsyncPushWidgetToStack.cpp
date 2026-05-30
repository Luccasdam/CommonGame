// Copyright Luccas de Avila Machado. All rights reserved.


#include "UI/Async/CG_UI_AsyncPushWidgetToStack.h"
#include "UI/System/CG_UI_Subsystem.h"


UCG_UI_AsyncPushWidgetToStack* UCG_UI_AsyncPushWidgetToStack::PushWidgetToStack(const UObject* WorldContextObject, APlayerController* OwningPlayerController, TSoftClassPtr<UCG_UI_W_ActivatableWidget> InWidgetClass, const FGameplayTag InLayerTag,
																				bool bFocusOnNewlyPushedWidget)
{
	checkf(!InWidgetClass.IsNull(), TEXT("Insert a valid Widget Class."))
	
	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			UCG_UI_AsyncPushWidgetToStack* Action = NewObject<UCG_UI_AsyncPushWidgetToStack>();
			Action->CachedWorld = World;
			Action->CachedOwningPlayerController = OwningPlayerController;
			Action->CachedWidgetClass = InWidgetClass;
			Action->CachedLayerTag = InLayerTag;
			Action->bCachedFocusOnNewlyCreatedWidget = bFocusOnNewlyPushedWidget;
			Action->RegisterWithGameInstance(World);
			return Action;
		}
	}
	
	return nullptr;
}


void UCG_UI_AsyncPushWidgetToStack::Activate()
{
	UCG_UI_Subsystem* UISubsystem = UCG_UI_Subsystem::Get(CachedWorld.Get());
	check(UISubsystem)
	
	UISubsystem->PushWidgetToLayerStackAsync(
		CachedLayerTag,
		CachedWidgetClass,
		[this](const EAsyncWidgetPushState PushState, UCG_UI_W_ActivatableWidget* PushedWidgetInstance)
		{
			switch (PushState)
			{
				case EAsyncWidgetPushState::OnCreatedBeforePush:
				{
					PushedWidgetInstance->SetOwningPlayer(CachedOwningPlayerController.Get());
					OnWidgetCreatedBeforePush.Broadcast(PushedWidgetInstance);
					break;
				}
				case EAsyncWidgetPushState::AfterPush:
				{
					AfterPush.Broadcast(PushedWidgetInstance);
						
					if (bCachedFocusOnNewlyCreatedWidget)
					{
						PushedWidgetInstance->RequestRefreshFocus();
					}
						
					SetReadyToDestroy();
				}
			}
		}
	);
}
