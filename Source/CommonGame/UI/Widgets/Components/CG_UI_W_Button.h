// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CG_UI_W_Button.generated.h"

class UCommonTextBlock;


/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class COMMONGAME_API UCG_UI_W_Button : public UCommonButtonBase
{
	GENERATED_BODY()
	
public:
	void SetDisplayText(const FText& ButtonText);
	
protected:
	virtual void NativePreConstruct() override;
	virtual void NativeOnCurrentTextStyleChanged() override;
	
	void UpdateText() const;
	
	
protected:
	UPROPERTY(meta=(BindWidgetOptional))
	TObjectPtr<UCommonTextBlock> CTB_ButtonText;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FText DisplayText;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	bool bForceUppercase = false;
};
