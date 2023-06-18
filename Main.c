#include "UI.h"
#include "InGame.h"
#include "Cursor.h"
int main() {
	int state = 0;
	while (1) {
		if (state == 0) {
			state = printStartTitle();
			if (state == 2) {
				break;
			}
			state = InGame();
		}
		else if (state == 1) {
			state = InGame();
		}
		else {//state==2. quit game
			break;
		}
	}

	SetCurrentCursorPos(0, 40);
	return 0;
}