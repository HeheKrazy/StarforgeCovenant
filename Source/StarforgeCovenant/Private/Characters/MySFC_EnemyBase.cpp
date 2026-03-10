// Copyright HeheKrazy


#include "Characters/MySFC_EnemyBase.h"
#include "AbilitySystem/SFCAbilitySystemComponent.h"
#include "AbilitySystem/SFCAttributeSet.h"
#include "StarforgeCovenant/StarforgeCovenant.h"

AMySFC_EnemyBase::AMySFC_EnemyBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<USFCAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	//Gameplay effects are NOT replicated. Gameplay Cues and Gameplay Tags are replicated to all clients.
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<USFCAttributeSet>("AttributeSet");
}

void AMySFC_EnemyBase::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AMySFC_EnemyBase::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AMySFC_EnemyBase::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
}
