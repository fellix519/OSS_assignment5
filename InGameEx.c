#include "Cursor.h"
#include "InGame.h"
//기타 함수
void check(int n) {
	COORD c = GetCurrentCursorPos();
	SetCurrentCursorPos(0, 0);
	printf("%d", n);
	Sleep(2000);
	SetCurrentCursorPos(c.X, c.Y);
}
void setCurrentPlayerPos(int x1, int y1) {
	curPos.X = GBOARD_ORIGIN_X + x1;
	curPos.Y = GBOARD_ORIGIN_Y + y1;
}