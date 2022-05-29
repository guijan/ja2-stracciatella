#ifndef TURN_BASED_INPUT_H
#define TURN_BASED_INPUT_H

#include "Handle_UI.h"
#include "JA2Types.h"

extern const SOLDIERTYPE* gUITargetSoldier;

void GetTBMouseButtonInput(UIEventKind* puiNewEvent);
void GetTBMousePositionInput(UIEventKind* puiNewEvent);

INT8    HandleMoveModeInteractiveClick(UINT16 usMapPos);
BOOLEAN HandleUIReloading(SOLDIERTYPE* pSoldier);

#endif
