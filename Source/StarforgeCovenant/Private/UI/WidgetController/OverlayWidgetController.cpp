// Copyright HeheKrazy


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/SFCAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USFCAttributeSet* SFCAttributeSet = CastChecked<USFCAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(SFCAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(SFCAttributeSet->GetMaxHealth());
	
}
