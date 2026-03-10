// Copyright HeheKrazy


#include "Characters/SFC_Character.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SFCPlayerState.h"

ASFC_Character::ASFC_Character()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ASFC_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	//Inity ability actor info for the server
	InitAbilityActorInfo();
}

void ASFC_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
	
}

void ASFC_Character::InitAbilityActorInfo()
{	
	// Get PlayerState first
	ASFCPlayerState* SfcPlayerState = GetPlayerState<ASFCPlayerState>();
	check(SfcPlayerState);
	SfcPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SfcPlayerState, this);
	AbilitySystemComponent = SfcPlayerState->GetAbilitySystemComponent();
	AttributeSet = SfcPlayerState->GetAttributeSet();
}
