// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UI/Widgets/CG_UI_W_ActivatableWidget.h"
#include "CG_UI_Subsystem.generated.h"

struct FGameplayTag;
class UCG_UI_W_RootLayout;
class UCG_UI_W_ActivatableWidget;
class UMVVMViewModelBase;


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
	
	
	// Get the current view model instance.
	UFUNCTION(BlueprintCallable, Category="CommonGame|UI|Subsystem")
	UMVVMViewModelBase* GetCurrentViewModel() const { return CurrentViewModel; }
	
	// Request a view model, it will fetch an existing one if it exists and matches the desired class otherwise it will create a new instance.
	UFUNCTION(BlueprintCallable, Category="CommonGame|UI|Subsystem")
	UMVVMViewModelBase* RequestViewModel(UClass* DesiredViewModelClass);
	
private:
	UPROPERTY(Transient)
	TObjectPtr<UCG_UI_W_RootLayout> RootLayoutWidget;
	
	UPROPERTY(Transient)
	TObjectPtr<UMVVMViewModelBase> CurrentViewModel;
};
