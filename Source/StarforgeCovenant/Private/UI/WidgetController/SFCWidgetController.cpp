// Copyright HeheKrazy


#include "UI/WidgetController/SFCWidgetController.h"

void USFCWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void USFCWidgetController::BroadcastInitialValues()
{
}

void USFCWidgetController::BindCallbacksToDependencies()
{
}
