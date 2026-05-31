// Copyright Luccas de Avila Machado. All rights reserved.


#include "UI/Widgets/Components/CG_UI_W_Button.h"
#include "CommonTextBlock.h"


void UCG_UI_W_Button::SetDisplayText(const FText& ButtonText)
{
	DisplayText = ButtonText;
	UpdateText();
}

void UCG_UI_W_Button::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	UpdateText();
}

void UCG_UI_W_Button::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();
	
	if (CTB_ButtonText && GetCurrentTextStyleClass())
	{
		CTB_ButtonText->SetStyle(GetCurrentTextStyleClass());
	}
}

void UCG_UI_W_Button::UpdateText() const
{
	if (!CTB_ButtonText)
	{
		return;
	}
	
	CTB_ButtonText->SetVisibility(DisplayText.IsEmpty() ? ESlateVisibility::Collapsed : ESlateVisibility::SelfHitTestInvisible);
	CTB_ButtonText->SetText(DisplayText);
	CTB_ButtonText->SetTextCase(bForceUppercase);
}
