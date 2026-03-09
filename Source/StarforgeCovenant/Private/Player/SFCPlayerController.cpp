// Copyright HeheKrazy


#include "Player/SFCPlayerController.h"
#include  "EnhancedInputSubsystems.h"

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
