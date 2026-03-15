// Copyright HeheKrazy


#include "AbilitySystem/SFCAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

USFCAttributeSet::USFCAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitEnergy(100.f);
	InitMaxEnergy(100.f);
	
}

void USFCAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(USFCAttributeSet, Health, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(USFCAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(USFCAttributeSet, Energy, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(USFCAttributeSet, MaxEnergy, COND_None, REPNOTIFY_Always)
}

void USFCAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USFCAttributeSet, Health, OldHealth);
}

void USFCAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USFCAttributeSet, MaxHealth, OldMaxHealth);
}

void USFCAttributeSet::OnRep_Energy(const FGameplayAttributeData& OldEnergy) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USFCAttributeSet, Energy, OldEnergy);
}

void USFCAttributeSet::OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy)  const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USFCAttributeSet, MaxEnergy, OldMaxEnergy);
}
