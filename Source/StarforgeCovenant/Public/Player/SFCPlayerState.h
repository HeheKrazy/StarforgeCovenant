// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "SFCPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
/**
 * 
 */
UCLASS()
class STARFORGECOVENANT_API ASFCPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ASFCPlayerState();
	//Override from IAbilitySystemInterface needs implemented on each class that inherits from it
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const;
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
