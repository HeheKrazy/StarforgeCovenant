// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "SFCAttributeSet.generated.h"

/**
 * To add attributes, create FGameplayAttributeData variable.
 * - create OnRep_Attribute()
 * - Override GetLifetimeReplicatedProps()
 * -DOREPLIFETIME_CONDITION_NOTIFY in GetLifetimeReplicatedProps()
 * 
 */
UCLASS()
class STARFORGECOVENANT_API USFCAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	USFCAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	/* Attributes */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Energy, Category = "Vital Attributes")
	FGameplayAttributeData Energy;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxEnergy, Category = "Vital Attributes")
	FGameplayAttributeData MaxEnergy;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	UFUNCTION()
	void OnRep_Energy(const FGameplayAttributeData& OldEnergy) const;
	UFUNCTION()
	void OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy) const;
	/* end Attributes */
	
};
