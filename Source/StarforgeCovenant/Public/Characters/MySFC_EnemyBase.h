// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Characters/SFC_CharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "MySFC_EnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class STARFORGECOVENANT_API AMySFC_EnemyBase : public ASFC_CharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	virtual void HighlightActor();
	virtual void UnHighlightActor();
	
	UPROPERTY(BlueprintReadOnly, Category = "Debug")
	bool bActorHighlighted = false;
	
};
