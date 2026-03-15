// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SFCHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class USFCUserWidget;
class UOverlayWidgetController;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class STARFORGECOVENANT_API ASFCHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	TObjectPtr<USFCUserWidget> OverlayWidget;
	
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	
	void InitOverlay(APlayerController* PC, APlayerState* PState, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<USFCUserWidget> OverlayWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
};
