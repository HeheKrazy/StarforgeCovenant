// Copyright HeheKrazy


#include "Player/SFCPlayerState.h"

#include "AbilitySystem/SFCAbilitySystemComponent.h"
#include "AbilitySystem/SFCAttributeSet.h"

ASFCPlayerState::ASFCPlayerState()
{	
	//Still have to set in player this will only be valid on PlayerState
	AbilitySystemComponent = CreateDefaultSubobject<USFCAbilitySystemComponent>("AbilitySystemComponent");
 	AbilitySystemComponent->SetIsReplicated(true);
 	
 	AttributeSet = CreateDefaultSubobject<USFCAttributeSet>("AttributeSet");
	
	// Controls how often this actor replicates updates to clients (times per second).
	// Higher values = smoother updates but more network bandwidth usage.
	SetNetUpdateFrequency(100.f);
	

}

UAbilitySystemComponent* ASFCPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ASFCPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
