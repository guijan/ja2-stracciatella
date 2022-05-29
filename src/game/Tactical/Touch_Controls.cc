#include "Touch_Controls.h"
#include "Button_System.h"
#include "Soldier_Find.h"
#include "Font_Control.h"
#include "WorldDef.h"
#include "RenderWorld.h"

#define TOUCH_CONFIRMATION_BUTTON_WIDTH 40
#define TOUCH_CONFIRMATION_BUTTON_HEIGHT 30

class TouchConfirmationDialog;

std::unique_ptr<TouchConfirmationDialog> gTouchConfirmationDialog(nullptr);

class TouchConfirmationDialog {
	public:
		TouchConfirmationDialog(GridNo gridNo_, UINT8 level_) : gridNo(gridNo_), level(level_) {
			confirmButton = CreateTextButton("Confirm", FONT12ARIAL, FONT_BLACK, FONT_BLACK, 0, 0, TOUCH_CONFIRMATION_BUTTON_WIDTH, TOUCH_CONFIRMATION_BUTTON_HEIGHT, MSYS_PRIORITY_HIGH, MSYS_NO_CALLBACK);
			cancelButton = CreateTextButton("Cancel", FONT12ARIAL, FONT_BLACK, FONT_BLACK, 0, 0, TOUCH_CONFIRMATION_BUTTON_WIDTH, TOUCH_CONFIRMATION_BUTTON_HEIGHT, MSYS_PRIORITY_HIGH, MSYS_NO_CALLBACK);
			update();
		}

		// change grid no for touch confirmation dialog
		void updateGridNo(GridNo gridNo) {
			if (this->gridNo != gridNo) {
				this->gridNo = gridNo;
				update();
			}
		}

		// update button positions, when scrolling etc.
		void update() {
			INT16 gridX, gridY;
			GetGridNoScreenPos(gridNo, level, &gridX, &gridY);

			INT16 centerBottomX = gridX + WORLD_TILE_X / 2;
			INT16 centerBottomY = gridY + WORLD_TILE_Y;
			INT16 padding = WORLD_TILE_Y / 2;

			(*confirmButton).Area.RegionTopLeftX = centerBottomX + padding;
			(*confirmButton).Area.RegionTopLeftY = centerBottomY + padding;
			(*confirmButton).Area.RegionBottomRightX = (*confirmButton).Area.RegionTopLeftX + TOUCH_CONFIRMATION_BUTTON_WIDTH;
			(*confirmButton).Area.RegionBottomRightY = (*confirmButton).Area.RegionTopLeftY + TOUCH_CONFIRMATION_BUTTON_HEIGHT;

			(*cancelButton).Area.RegionTopLeftX = centerBottomX - padding - TOUCH_CONFIRMATION_BUTTON_WIDTH;
			(*cancelButton).Area.RegionTopLeftY = centerBottomY + padding;
			(*cancelButton).Area.RegionBottomRightX = (*cancelButton).Area.RegionTopLeftX + TOUCH_CONFIRMATION_BUTTON_WIDTH;
			(*cancelButton).Area.RegionBottomRightY = (*cancelButton).Area.RegionTopLeftY + TOUCH_CONFIRMATION_BUTTON_HEIGHT;

			MarkAButtonDirty(confirmButton);
			MarkAButtonDirty(cancelButton);

			SetRenderFlags( RENDER_FLAG_FULL );
		}
	private:
		GridNo gridNo;
		uint8_t level;
		GUIButtonRef confirmButton;
		GUIButtonRef cancelButton;
};

namespace TacticalTouchControls {
	void showConfirmationDialog(GridNo gridNo, uint8_t level) {
		if (gTouchConfirmationDialog) {
			gTouchConfirmationDialog.get()->updateGridNo(gridNo);
		} else {
			gTouchConfirmationDialog.reset(new TouchConfirmationDialog(gridNo, level));
		}
	}

	void hideConfirmationDialog() {
		gTouchConfirmationDialog.reset(nullptr);
	}

	void updateConfirmationDialog() {

	}
}
