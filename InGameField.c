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
int JumpToNextStage() {
	//캐릭터 위치가 벽을 남겨두고 4칸 앞에 있는지 확인
	//만약 그러면 돌기 모션 하면서 다음 90도 회전된 캐릭터 모양 만들기
	//다음 스테이지 시작
	switch (rotatedStage) {
	case 0:
		if (curPos.X >= GBOARD_ORIGIN_X + (GBOARD_WIDTH - 2) * 2) {
			rotatedStage++;
			curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - 8;
			curPos.Y = GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 6;
			return 1;
		}
	case 1:
		if (curPos.Y <= GBOARD_ORIGIN_Y + 1) {
			rotatedStage++;
			curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - 12;
			curPos.Y = GBOARD_ORIGIN_Y + 1;
			return 1;
		}
	case 2:

		if (curPos.X <= GBOARD_ORIGIN_X + 2) {
			rotatedStage++;
			curPos.X = GBOARD_ORIGIN_X + 2;
			curPos.Y = GBOARD_ORIGIN_Y + 5;
			return 1;
		}
	case 3:
		if (curPos.Y >= GBOARD_ORIGIN_Y + GBOARD_HEIGHT) {
			resetGame();
			printEndingScreen();
			return 2;
		}
	default:
		return 0;
	}
}
void DrawGameBoard(int rotatedStage) {
	int HorV = GBOARD_WIDTH;
	int*p =NULL;
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
void CreateWall() {
	switch (rotatedStage) {
	case 0:
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH - 1) * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - i - 1);
			printf("▩");
		}
		break;
	case 1:
		for (int i = 0; i < GBOARD_WIDTH; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + i * 2, GBOARD_ORIGIN_Y);
			printf("▩");
		}
		break;
	case 2:
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - i - 1);
			printf("▩");
		}
		break;
	case 3:
		for (int i = 0; i < GBOARD_WIDTH - 4; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + (i + 4) * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
			printf("▩");
		}
		break;
	default:
		break;
	}
}