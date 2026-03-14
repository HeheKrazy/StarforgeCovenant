// Copyright HeheKrazy


#include "UI/Widget/SFCUserWidget.h"

void USFCUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
