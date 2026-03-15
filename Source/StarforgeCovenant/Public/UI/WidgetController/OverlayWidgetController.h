// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/SFCWidgetController.h"
#include "OverlayWidgetController.generated.h"

/*Delegates*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
/*end Delegates*/

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class STARFORGECOVENANT_API UOverlayWidgetController : public USFCWidgetController
{
	GENERATED_BODY()
	
public:
	virtual void BroadcastInitialValues();
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;
	
};
