// Copyright HeheKrazy


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/SFCAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USFCAttributeSet* SFCAttributeSet = CastChecked<USFCAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(SFCAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(SFCAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const USFCAttributeSet* SFCAttributeSet = CastChecked<USFCAttributeSet>(AttributeSet);
	
	//Health
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SFCAttributeSet->GetHealthAttribute()).AddUObject(
		this,&UOverlayWidgetController::HealthChanged);
	
	//Max Health
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SFCAttributeSet->GetMaxHealthAttribute()).AddUObject(
		this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{	
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
