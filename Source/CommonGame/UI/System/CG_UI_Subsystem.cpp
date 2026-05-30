// Copyright Luccas de Avila Machado. All rights reserved.


#include "CG_UI_Subsystem.h"


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
