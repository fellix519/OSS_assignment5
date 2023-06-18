#include "InGame.h"
#include "Cursor.h"
#include "Character.h"
#include "Model.h"
#include "UI.h"
#include "Root.h"
#include<conio.h>
#pragma comment(lib,"winmm.lib")
//필드 관련 함수
void dropPlayer() {

	for (int i = 0; i < 8; i++) {
		//SetCurrentCursorPos(GBOARD_ORIGIN_X + STARTING_POINT_WIDTH * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - STARTING_POINT_HEIGHT + i);
		Showcharacter(Character[0], GBOARD_ORIGIN_X + STARTING_POINT_WIDTH * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - STARTING_POINT_HEIGHT + i);
		Sleep(50);
		if (i < 7)
			DeleteCh(Character[0], GBOARD_ORIGIN_X + STARTING_POINT_WIDTH * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - STARTING_POINT_HEIGHT + i);
	}
	SetCurrentCursorPos(0, 0);
}
//int JumpToNextStage()
void DrawGameBoard(int rotatedStage) {
	int HorV = GBOARD_WIDTH;
	int* p;
	if (rotatedStage % 2 == 0) {
		HorV = GBOARD_WIDTH;
		p = gameBoardInfoHorizon;
	}
	else if (rotatedStage % 2 == 1) {
		HorV = GBOARD_HEIGHT;
		p = gameBoardInfoVertical;
	}
	for (int i = 0; i < HorV; i++) {
		p[i] = -1;
	}
	system("cls");
	switch (rotatedStage) {
	case 0:
		RATE = 40;
		for (int i = 0; i < GBOARD_WIDTH; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + i * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
			printf("▩");
		}
		break;
	case 1:
		RATE = 30;
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH - 1) * 2, GBOARD_ORIGIN_Y + i);
			printf("▩");
		}
		break;
	case 2:
		RATE = 25;
		for (int i = 0; i < GBOARD_WIDTH; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + i * 2, GBOARD_ORIGIN_Y);
			printf("▩");
		}
		break;
	case 3:
		RATE = 20;
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + i);
			printf("▩");
		}
		break;
	default:
		break;
	}
}
//void CreateWall()