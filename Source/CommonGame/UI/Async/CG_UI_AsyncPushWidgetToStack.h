// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "CG_UI_AsyncPushWidgetToStack.generated.h"

class UCG_UI_W_ActivatableWidget;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPushWidgetDelegate, UCG_UI_W_ActivatableWidget*, PushedWidget);


/**
 * 
 */
UCLASS()
class COMMONGAME_API UCG_UI_AsyncPushWidgetToStack : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable, Category="CommonGame|UI|Async", meta=(WorldContext="WorldContextObject", HidePin="WorldContextObject", DisplayName="Push Widget To Stack", BlueprintInternalUseOnly=true))
	static UCG_UI_AsyncPushWidgetToStack* PushWidgetToStack(
		const UObject* WorldContextObject,
		APlayerController* OwningPlayerController,
		TSoftClassPtr<UCG_UI_W_ActivatableWidget> InWidgetClass,
		UPARAM(meta=(Categories="UI.Layer")) const FGameplayTag InLayerTag,
		bool bFocusOnNewlyPushedWidget = true
	);
	
	virtual void Activate() override;
	
	UPROPERTY(BlueprintAssignable)
	FOnPushWidgetDelegate OnWidgetCreatedBeforePush;
	
	UPROPERTY(BlueprintAssignable)
	FOnPushWidgetDelegate AfterPush;
	
	
private:
	TWeakObjectPtr<UWorld> CachedWorld;
	TWeakObjectPtr<APlayerController> CachedOwningPlayerController;
	TSoftClassPtr<UCG_UI_W_ActivatableWidget> CachedWidgetClass;
	FGameplayTag CachedLayerTag;
	bool bCachedFocusOnNewlyCreatedWidget = false;
};
