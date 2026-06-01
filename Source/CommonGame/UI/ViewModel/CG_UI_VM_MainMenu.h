// Copyright Luccas de Avila Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "CG_UI_VM_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class COMMONGAME_API UCG_UI_VM_MainMenu : public UMVVMViewModelBase
{
	GENERATED_BODY()
	
protected:
	FText GetButtonDescriptionText() const { return ButtonDescriptionText; }
	void SetButtonDescriptionText(const FText& NewDescriptionText);
	
	
private:
	UPROPERTY(BlueprintReadWrite, FieldNotify, Getter, Setter, meta=(AllowPrivateAccess))
	FText ButtonDescriptionText;
};
