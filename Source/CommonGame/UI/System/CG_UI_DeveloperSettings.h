// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "CG_UI_DeveloperSettings.generated.h"

class UCG_UI_W_RootLayout;

/**
 * 
 */
UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Common Game UI Settings"))
class COMMONGAME_API UCG_UI_DeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, Config, Category="Widgets")
	TSubclassOf<UCG_UI_W_RootLayout> RootLayoutWidgetClass;
};
