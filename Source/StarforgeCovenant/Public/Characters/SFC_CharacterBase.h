// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SFC_CharacterBase.generated.h"

UCLASS(Abstract)
class STARFORGECOVENANT_API ASFC_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASFC_CharacterBase();

protected:
	virtual void BeginPlay() override;
};
