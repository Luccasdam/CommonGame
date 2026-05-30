// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UI/Widgets/CG_UI_W_ActivatableWidget.h"
#include "CG_UI_Subsystem.generated.h"

struct FGameplayTag;
class UCG_UI_W_RootLayout;
class UCG_UI_W_ActivatableWidget;


enum class EAsyncWidgetPushState : uint8
{
	OnCreatedBeforePush,
	AfterPush
};


/**
 * 
 */
UCLASS()
class COMMONGAME_API UCG_UI_Subsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	static UCG_UI_Subsystem* Get(const UObject* WorldContextObject);
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	
	UFUNCTION(BlueprintCallable, Category="CommonGame|UI|Subsystem")
	void RegisterRootLayoutWidget(UCG_UI_W_RootLayout* InRootLayoutWidget);
	
	void PushWidgetToLayerStackAsync(const FGameplayTag& InLayerTag, TSoftClassPtr<UCG_UI_W_ActivatableWidget> InWidgetClass, TFunction<void(EAsyncWidgetPushState, UCG_UI_W_ActivatableWidget*)> AsyncPushCallback) const;
	
	
private:
	UPROPERTY(Transient)
	TObjectPtr<UCG_UI_W_RootLayout> RootLayoutWidget;
};
