// Copyright Luccas de Avila Machado. All rights reserved.


#include "UI/ViewModel/CG_UI_VM_MainMenu.h"


void UCG_UI_VM_MainMenu::SetButtonDescriptionText(const FText& NewDescriptionText)
{
	UE_MVVM_SET_PROPERTY_VALUE(ButtonDescriptionText, NewDescriptionText);
}
