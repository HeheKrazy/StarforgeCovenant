// Copyright HeheKrazy


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/SFCAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USFCAttributeSet* SFCAttributeSet = CastChecked<USFCAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(SFCAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(SFCAttributeSet->GetMaxHealth());
	OnShieldChanged.Broadcast(SFCAttributeSet->GetShield());
	OnMaxShieldChanged.Broadcast(SFCAttributeSet->GetMaxShield());
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
	
	//Shield
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SFCAttributeSet->GetShieldAttribute()).AddUObject(
		this, &UOverlayWidgetController::ShieldChanged);
	
	//MaxShield
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SFCAttributeSet->GetMaxShieldAttribute()).AddUObject(
		this, &UOverlayWidgetController::MaxShieldChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{	
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ShieldChanged(const FOnAttributeChangeData& Data) const
{
	OnShieldChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxShieldChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxShieldChanged.Broadcast(Data.NewValue);
}
