// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SFCPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class STARFORGECOVENANT_API ASFCPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASFCPlayerController();
	
protected:
virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> SFCContext;
	
};
