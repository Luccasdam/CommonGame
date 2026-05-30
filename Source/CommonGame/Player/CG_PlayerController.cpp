// Copyright Luccas de Avila Machado. All rights reserved.


#include "CG_PlayerController.h"
#include "UI/System/CG_UI_Subsystem.h"
#include "UI/System/CG_UI_DeveloperSettings.h"
#include "UI/Widgets/CG_UI_W_RootLayout.h"


void ACG_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsLocalController())
	{
		// Fetch the Project class for the Root Layout
		const UCG_UI_DeveloperSettings* UISettings = GetDefault<UCG_UI_DeveloperSettings>();
		checkf(UISettings->RootLayoutWidgetClass, TEXT("Please insert a valid Root Layout Widget class into UI Settings"))
		
		// Create and Assign the Root Layout Widget into the UI Subsystem
		UCG_UI_Subsystem* UISubsystem = UCG_UI_Subsystem::Get(this);
		UCG_UI_W_RootLayout* RootLayoutWidget = CreateWidget<UCG_UI_W_RootLayout>(this, UISettings->RootLayoutWidgetClass);
		
		UISubsystem->RegisterRootLayoutWidget(RootLayoutWidget);
		RootLayoutWidget->AddToViewport();
	}
}
