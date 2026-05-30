// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "CG_UI_W_RootLayout.generated.h"

class UCommonActivatableWidgetContainerBase;


/**
 * 
 */
UCLASS(Abstract, meta=(DisableNativeTick))
class COMMONGAME_API UCG_UI_W_RootLayout : public UCommonUserWidget
{
	GENERATED_BODY()
	
public:
	UCommonActivatableWidgetContainerBase* FindWidgetStackByLayerTag(const FGameplayTag& InLayerTag);
	
protected:
	UFUNCTION(BlueprintCallable)
	void RegisterWidgetStackToLayer(UPARAM(meta=(Categories="UI.Layer")) FGameplayTag InLayerTag, UCommonActivatableWidgetContainerBase* InWidgetStack);
	
	
private:
	UPROPERTY()
	TMap<FGameplayTag, UCommonActivatableWidgetContainerBase*> WidgetStacks;
};
