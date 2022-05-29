#pragma once

#include "Types.h"
#include "JA2Types.h"

namespace TacticalTouchControls {
	bool mouseIsOverConfirmationDialog();

	void showConfirmationDialog(GridNo gridNo, uint8_t level);
	void hideConfirmationDialog();
	void updateConfirmationDialog();
}
