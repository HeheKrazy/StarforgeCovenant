// Copyright HeheKrazy


#include "Player/SFCPlayerController.h"
#include  "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Characters/SFC_Character.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interaction/EnemyInterface.h"
#include "Runtime/ApplicationCore/Internal/GenericPlatform/CursorUtils.h"

ASFCPlayerController::ASFCPlayerController()
{
	bReplicates = true;
}

void ASFCPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void ASFCPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	//Need to set in the BP
	check(SFCContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	//Ensure Subsystem isn't null
	check(Subsystem);
	Subsystem->AddMappingContext(SFCContext, 0);
	
	//Changed for third person testing to false and added click events and mouse over events
	bShowMouseCursor = false;
	bEnableClickEvents = false;
	bEnableMouseOverEvents = false;
	
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameOnly InputModeData;
	SetInputMode(InputModeData);
}

void ASFCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//Ensure InputComponent is valid
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	//Bind Input Actions to Function Callbacks
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Started, this, &ASFCPlayerController::OnMoveStarted);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASFCPlayerController::Move);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ASFCPlayerController::OnMoveStopped);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Canceled, this, &ASFCPlayerController::OnMoveStopped);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASFCPlayerController::Look);
}

void ASFCPlayerController::Move(const FInputActionValue& InputActionValue)
{
	//Convert to vector 2d
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	
	
	//Find forward Direction
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ASFCPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	AddYawInput(InputAxisVector.Y);
	AddPitchInput(InputAxisVector.X);
}

void ASFCPlayerController::OnMoveStarted(const FInputActionValue& InputActionValue)
{
	if (const ASFC_Character* ControlledCharacter = Cast<ASFC_Character>(GetPawn()))
	{
		ControlledCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
	}
}

void ASFCPlayerController::OnMoveStopped(const FInputActionValue& InputActionValue)
{
	if (const ASFC_Character* ControlledCharacter = Cast<ASFC_Character>(GetPawn()))
	{
		ControlledCharacter->GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}

void ASFCPlayerController::CursorTrace()
{
	/*
	 *Trace for actors under cursor to use in IEnemyInterface virtual pure functions on the Enemy Class's
	 *HighlightActor()
	 *UnHighlightActor()
	 */
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	
	LastActor = ThisActor;
	ThisActor = (CursorHit.GetActor());
	
	/*
	* Line trace from cursor. There are several scenarios:
	* A. LastActor is null && ThisActor is null
	*	-Do nothing
	* B. LastActor is null && ThisActor is valid
	*	- Highlight ThisActor
	* C. LastActor is valid && ThisActor is null
	*	- UnHighlight LastActor
	* D. Both Actors are valid but LastActor != ThisActor
	*	- UnHighlight LastActor, and Highlight ThisActor
	* E. Both Actors are valid, and are the same actor
	*	- Do nothing
	* */
	
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			//Case B
			ThisActor->HighlightActor();
		}
		else
		{
			//Case A both are null, do nothing
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			//Case C
			LastActor->UnHighlightActor();
		}
		else //Both actors are valid
		{
			if (LastActor != ThisActor)
			{
				//Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case E do nothing
			}
		}
	}
	
}
