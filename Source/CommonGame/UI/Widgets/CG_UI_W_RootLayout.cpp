// Copyright Luccas de Avila Machado. All rights reserved.


#include "CommonGame/UI/Widgets/CG_UI_W_RootLayout.h"


UCommonActivatableWidgetContainerBase* UCG_UI_W_RootLayout::FindWidgetStackByLayerTag(const FGameplayTag& InLayerTag)
{
	checkf(InLayerTag.IsValid(), TEXT("Please insert a valid gameplay tag."))
	checkf(WidgetStacks.Contains(InLayerTag), TEXT("No valid WidgetStack for Layer %s."), *InLayerTag.ToString())
	
	return WidgetStacks.FindRef(InLayerTag);
}

void UCG_UI_W_RootLayout::RegisterWidgetStackToLayer(FGameplayTag InLayerTag, UCommonActivatableWidgetContainerBase* InWidgetStack)
{
	checkf(InLayerTag.IsValid(), TEXT("Please insert a valid gameplay tag."))
	checkf(InWidgetStack, TEXT("Cannot Register a WidgetStack without a valid Widget Container."))
	
	// If we are not in design time & WidgetStacks does not contain a container for the layer.
	if (!IsDesignTime() && !WidgetStacks.Contains(InLayerTag))
	{
		WidgetStacks.Add(InLayerTag, InWidgetStack);
	}
}
