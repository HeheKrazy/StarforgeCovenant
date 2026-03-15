// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/SFCWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
/*Delegates*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShieldChangedSignature, float, NewShield);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxShieldChangedSignature, float, NewMaxShield);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergyChangedSignature, float, NewEnergy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxEnergyChangedSignature, float, NewMaxEnergy);
/*end Delegates*/

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class STARFORGECOVENANT_API UOverlayWidgetController : public USFCWidgetController
{
	GENERATED_BODY()
	
public:
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnShieldChangedSignature OnShieldChanged;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxShieldChangedSignature OnMaxShieldChanged;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnEnergyChangedSignature OnEnergyChanged;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxEnergyChangedSignature OnMaxEnergyChanged;

protected:
	
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void ShieldChanged(const FOnAttributeChangeData& Data) const;
	void MaxShieldChanged(const FOnAttributeChangeData& Data) const;
	void EnergyChanged(const FOnAttributeChangeData& Data) const;
	void MaxEnergyChanged(const FOnAttributeChangeData& Data) const;
};