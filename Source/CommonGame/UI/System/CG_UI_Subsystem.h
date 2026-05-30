// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CG_UI_Subsystem.generated.h"

class UCG_UI_W_RootLayout;

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
	
	
private:
	UPROPERTY(Transient)
	TObjectPtr<UCG_UI_W_RootLayout> RootLayoutWidget;
};
