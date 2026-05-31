// Copyright Luccas de Avila Machado. All rights reserved.


#include "UI/System/CG_UI_FunctionLibrary.h"
#include "CG_UI_DeveloperSettings.h"
#include "GameplayTagContainer.h"


TSoftClassPtr<UCG_UI_W_ActivatableWidget> UCG_UI_FunctionLibrary::GetWidgetScreenByTag(const FGameplayTag ScreenTag)
{
	checkf(ScreenTag.IsValid(), TEXT("Insert a valid ScreenTag"))
	
	const UCG_UI_DeveloperSettings* Settings = GetDefault<UCG_UI_DeveloperSettings>();
	checkf(Settings->ScreenList.Contains(ScreenTag), TEXT("Could not find a valid Screen for Tag %s"), *ScreenTag.ToString())
	
	return  Settings->ScreenList.FindRef(ScreenTag);
}
