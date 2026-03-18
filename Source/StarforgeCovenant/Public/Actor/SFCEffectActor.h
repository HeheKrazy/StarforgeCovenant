// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SFCEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class STARFORGECOVENANT_API ASFCEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASFCEffectActor();
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	
};
