#include "InGame.h"
#include "Cursor.h"
#include "Character.h"
#include "Model.h"
#include "UI.h"
#include "Root.h"

#include<conio.h>
#pragma comment(lib,"winmm.lib")
//장애물 관련 함수
void shiftScreenLeft() {
	if (rotatedStage % 2 == 0) {
		//점프 적용 유무에 따라 다른 deleteObstacle 함수 실행
		if (jumpInfoHorizon[0] >= 0 && jumpArray[jumpInfoHorizon[0] % 16] > 0) {
			deleteObstacle(gameBoardInfoHorizon[0], 0, jumpArray[(jumpInfoHorizon[0] - 1) % 16]); //그 장애물의 최근 점프값 전달
		}
		else {
			deleteObstacle(gameBoardInfoHorizon[0], 0, -1);
		}
		for (int i = 0; i < GBOARD_WIDTH - 1; i++) {
			gameBoardInfoHorizon[i] = gameBoardInfoHorizon[i + 1];
			jumpInfoHorizon[i] = jumpInfoHorizon[i + 1];
		}
		if (currentTime >= gameInfoByStage[rotatedStage][obstacleCount][0]) {
			gameBoardInfoHorizon[GBOARD_WIDTH - 1] = gameInfoByStage[rotatedStage][obstacleCount][1];
			jumpInfoHorizon[GBOARD_WIDTH - 1] = gameInfoByStage[rotatedStage][obstacleCount][2];
			obstacleCount++;
		}
		else {
			gameBoardInfoHorizon[GBOARD_WIDTH - 1] = -1;
			jumpInfoHorizon[GBOARD_WIDTH - 1] = -1;
		}
	}
	else if (rotatedStage % 2 == 1) {
		if (jumpInfoVertical[0] >= 0 && jumpArray[jumpInfoVertical[0] % 16] > 0) {
			//printf("ss:%d", jumpArray[(jumpInfoVertical[0] - 1) % 16]); Sleep(500);
			deleteObstacle(gameBoardInfoVertical[0], 0, jumpArray[(jumpInfoVertical[0] - 1) % 16]); //그 장애물의 최근 점프값 전달
		}
		else {
			deleteObstacle(gameBoardInfoVertical[0], 0, -1);
		}
		for (int i = 0; i < GBOARD_HEIGHT - 1; i++) {
			gameBoardInfoVertical[i] = gameBoardInfoVertical[i + 1];
			jumpInfoVertical[i] = jumpInfoVertical[i + 1];
		}
		if (currentTime >= gameInfoByStage[rotatedStage][obstacleCount][0]) {
			gameBoardInfoVertical[GBOARD_HEIGHT - 1] = gameInfoByStage[rotatedStage][obstacleCount][1];
			jumpInfoVertical[GBOARD_HEIGHT - 1] = gameInfoByStage[rotatedStage][obstacleCount][2];
			obstacleCount++;
		}
		else {
			gameBoardInfoVertical[GBOARD_HEIGHT - 1] = -1;
			jumpInfoVertical[GBOARD_HEIGHT - 1] = -1;
		}

	}
}
int printObstacle() {
	clearScreen();
	if (rotatedStage % 2 == 0) {
		for (int tx = 0; tx < GBOARD_WIDTH; tx++) {
			//장애물 타입
			int type = gameBoardInfoHorizon[tx];
			//점프 여부
			int jump = jumpInfoHorizon[tx];
			if (type >= 100) {
				CreateWall();
				return 0;
			}
			else if (type != -1) {
				if (rotatedStage == 0) {
					if (jump >= 0) {
						//장애물이 점프해야할상황이면
						jumpInfoHorizon[tx]++;
						ShowBlock(Model[type], GBOARD_ORIGIN_X + tx * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 5 - jumpArray[jump % 16]);
					}
					else {
						ShowBlock(Model[type], GBOARD_ORIGIN_X + tx * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 5);
					}
				}
				else if (rotatedStage == 2) {
					if (jump >= 0) {
						//장애물이 점프해야할상황이면
						jumpInfoHorizon[tx]++;
						ShowBlock(Model[type], GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - tx * 2, GBOARD_ORIGIN_Y + jumpArray[jump % 16] + 1);
					}
					else {
						ShowBlock(Model[type], GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - tx * 2, GBOARD_ORIGIN_Y + 1);
					}
				}

			}
		}
	}
	else if (rotatedStage % 2 == 1) {
		for (int ty = 0; ty < GBOARD_HEIGHT; ty++) {
			int type = gameBoardInfoVertical[ty];
			int jump = jumpInfoVertical[ty];
			if (type >= 100) {
				CreateWall();
				return 0;
			}
			else if (type != -1) {
				if (rotatedStage == 1) {
					if (jump >= 0) {
						//장애물이 점프해야할상황이면
						jumpInfoVertical[ty]++;
						ShowBlock(Model[type], GBOARD_ORIGIN_X + (GBOARD_WIDTH - 6) * 2 - jumpArray[jump % 16] * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - ty);
					}
					else {
						ShowBlock(Model[type], GBOARD_ORIGIN_X + (GBOARD_WIDTH - 6) * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - ty);
					}
				}

				else if (rotatedStage == 3)
				{
					if (jump >= 0) {
						//장애물이 점프해야할상황이면
						jumpInfoVertical[ty]++;
						ShowBlock(Model[type], GBOARD_ORIGIN_X + 2 + jumpArray[jump % 16] * 2, GBOARD_ORIGIN_Y + ty);
					}
					else {
						ShowBlock(Model[type], GBOARD_ORIGIN_X + 2, GBOARD_ORIGIN_Y + ty);
					}

				}
			}
		}
	}

	return 1;
}
void deleteObstacle(int type, int tx, int para) {
	switch (rotatedStage)
	{
	case 0:
	{
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (Model[type][y][x] != 0) {
					//점프가 시작됐으면 위의 if 아니면 else
					if (para >= 0) {
						SetCurrentCursorPos(GBOARD_ORIGIN_X + tx * 2 + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 5 + y - para);
						printf("  ");
					}
					else {
						SetCurrentCursorPos(GBOARD_ORIGIN_X + tx * 2 + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 5 + y);
						printf("  ");
					}
				}
			}
		}
		break;
	}

	case 1:
	{
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (Model[type][y][x] != 0) {
					if (para >= 0) {
						SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH - 6) * 2 + x * 2 - para * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - tx + y);
						printf("  ");
					}
					else {
						SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH - 6) * 2 + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - tx + y);
						printf("  ");
					}
				}
			}
		}
		break;
	}


	case 2:
	{
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (Model[type][y][x] != 0) {
					if (para >= 0) {
						SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - tx * 2 + x * 2, GBOARD_ORIGIN_Y + 1 + y + para);
						printf("  ");
					}
					else {
						SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - tx * 2 + x * 2, GBOARD_ORIGIN_Y + 1 + y);
						printf("  ");
					}
				}
			}
		}
		break;
	}

	case 3:
	{
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (para >= 0) {
					SetCurrentCursorPos(GBOARD_ORIGIN_X + 2 + x * 2 + para * 2, GBOARD_ORIGIN_Y + tx + y);
					printf("  ");
				}
				else {
					SetCurrentCursorPos(GBOARD_ORIGIN_X + 2 + x * 2, GBOARD_ORIGIN_Y + tx + y);
					printf("  ");
				}
			}
		}
		break;
	}
	}
}