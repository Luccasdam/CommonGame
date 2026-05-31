// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CG_UI_FunctionLibrary.generated.h"

class UCG_UI_W_ActivatableWidget;

/**
 * 
 */
UCLASS()
class COMMONGAME_API UCG_UI_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintPure, Category="CommonGame|UI|FunctionLibrary")
	static TSoftClassPtr<UCG_UI_W_ActivatableWidget> GetWidgetScreenByTag(UPARAM(meta=(Categories="UI.Screen")) FGameplayTag ScreenTag);
};
