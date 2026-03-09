// Copyright HeheKrazy


#include "Player/SFCPlayerController.h"
#include  "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ASFCPlayerController::ASFCPlayerController()
{
	bReplicates = true;
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
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ASFCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//Ensure InputComponent is valid
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	//Bind Input Actions to Function Callbacks
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASFCPlayerController::Move);
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
