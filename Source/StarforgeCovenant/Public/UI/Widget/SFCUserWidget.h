// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SFCUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class STARFORGECOVENANT_API USFCUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
protected:
	
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
