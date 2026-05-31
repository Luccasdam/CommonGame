// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/WorldSettings.h"
#include "CG_WorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class COMMONGAME_API ACG_WorldSettings : public AWorldSettings
{
	GENERATED_BODY()
	
public:
	FORCEINLINE FGameplayTag GetScreenTag() const { return ScreenTag; }
	FORCEINLINE FGameplayTag GetLayerTag() const { return LayerTag; }
	
protected:
	// Screen to Add to Player during level initialization
	UPROPERTY(EditDefaultsOnly, Category=GameMode, meta=(Categories="UI.Screen"))
	FGameplayTag ScreenTag;
	
	// LayerStack that we should add the screen to.
	UPROPERTY(EditDefaultsOnly, Category=GameMode, meta=(Categories="UI.Layer"))
	FGameplayTag LayerTag;
};
