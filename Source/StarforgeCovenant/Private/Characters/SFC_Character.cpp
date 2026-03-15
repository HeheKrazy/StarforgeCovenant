// Copyright HeheKrazy


#include "Characters/SFC_Character.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SFCPlayerController.h"
#include "Player/SFCPlayerState.h"
#include "UI/HUD/SFCHUD.h"

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
	ASFCPlayerState* SFCPlayerState = GetPlayerState<ASFCPlayerState>();
	check(SFCPlayerState);
	SFCPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SFCPlayerState, this);
	AbilitySystemComponent = SFCPlayerState->GetAbilitySystemComponent();
	AttributeSet = SFCPlayerState->GetAttributeSet();
	
	if (ASFCPlayerController* SFCPlayerController = Cast<ASFCPlayerController>(GetController()))
	{
		if (ASFCHUD* HUD = Cast<ASFCHUD>(SFCPlayerController->GetHUD()))
		{
			HUD->InitOverlay(SFCPlayerController, SFCPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	
}
