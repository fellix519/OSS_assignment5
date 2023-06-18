#include "InGame.h"
#include "Cursor.h"
#include "Character.h"
#include "Model.h"
#include "UI.h"
#include "Root.h"

int printStartScreen() {
	DrawGameBoard(0);

	Showcharacter(Character[0], GBOARD_ORIGIN_X + STARTING_POINT_WIDTH * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - STARTING_POINT_HEIGHT);

	SetCurrentCursorPos(GBOARD_ORIGIN_X + 4, GBOARD_ORIGIN_Y + GBOARD_HEIGHT / 3);
	printf("Press \'SPACE\' Start!");

	int startButton;
	while (1) {
		startButton = _getch();
		if (startButton == SPACE) {
			break;
		}
	}
	deleteScreen(2, GBOARD_HEIGHT / 3, 32, GBOARD_HEIGHT / 3);

	return startButton;
}
void clearScreen() {
	if (rotatedStage % 2 == 0) {
		for (int tx = 0; tx < GBOARD_WIDTH; tx++) {
			int info = gameBoardInfoHorizon[tx];
			if (info != -1) {
				int jump = jumpInfoHorizon[tx];
				if (jump >= 1) {
					deleteObstacle(info, tx + 1, jumpArray[(jump - 1) % 16]);
				}
				else {
					deleteObstacle(info, tx + 1, -1);
				}
			}
		}
	}
	else {
		for (int ty = 0; ty < GBOARD_HEIGHT; ty++) {
			int info = gameBoardInfoVertical[ty];
			if (info != -1) {
				int jump = jumpInfoVertical[ty];
				if (jump >= 1) {
					//printf("cs:%d", jumpArray[(jump - 1) % 16]); Sleep(500);
					deleteObstacle(info, ty + 1, jumpArray[(jump - 1) % 16]);
				}
				else {
					deleteObstacle(info, ty + 1, -1);
				}
			}
		}
	}
}
void deleteScreen(int x1, int y1, int x2, int y2) {
	for (int y = y1; y <= y2; y++) {
		for (int x = x1; x <= x2; x++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + y);
			printf("  ");
		}
	}
}

void printEndingScreen() {
	system("cls");
	PlaySound(TEXT("Endding.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생

	system("cls");
	alignCenter(" \"아...안돼..15분....15분만 빨랐다면...\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" 교수님 : \"수현 학생은 오늘 부로 FA 처리 될 예정입니다. 다음 수업부터 나오지 않으셔도 됩니다.\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"교수님 제발...!!! 한번만...한번만 봐주세요!!!! 안돼요ㅠㅠ\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"안돼....!\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"........\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" 정적이 흐르는 방 안. 커튼 사이로 빛이 들어온다. ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"아 진짜가 아니였어... 정말 다행이야..", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"빨리 학교 갈 준비해야 겠다. 지금이 몇시지?", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("수현이는 시계를 봤다", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("11시 반을 가리키는 시계. 오늘 수업 시작은 1교시, 9시다.", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	_getch();
}
int printGameOver() {

	char msg1[] = "  Play Again";
	char msg1_2[] = "▶Play Again";
	char msg2[] = "  Go to Start Page";
	char msg2_2[] = "▶Go to Start Page";
	char msg3[] = "  Quit Game";
	char msg3_2[] = "▶Quit Game";
	int arrow = 0;
	int select;
	alignCenter("Game Over", midY - 7);
	while (1) {
		if (arrow == 0) {
			alignCenter(msg1_2, midY - 5);
			alignCenter(msg2, midY - 3);
			alignCenter(msg3, midY - 1);
		}
		else if (arrow == 1) {
			alignCenter(msg1, midY - 5);
			alignCenter(msg2_2, midY - 3);
			alignCenter(msg3, midY - 1);
		}
		else {
			alignCenter(msg1, midY - 5);
			alignCenter(msg2, midY - 3);
			alignCenter(msg3_2, midY - 1);
		}
		select = _getch();
		if (select == 224) {
			select = _getch();
			if (select == DOWN) { //Down 시 
				arrow++;
				if (arrow > 2) {
					arrow = 2;
				}
			}
			if (select == UP) { // UP 시
				arrow--;
				if (arrow < 0) {
					arrow = 0;
				}
			}
		}
		else if (select == SPACE || select == ENTER) { //Enter 클릭 시
			resetGame();

			if (arrow == 0) { // 가리키고 있는 버튼에 따라 다른 함수 실행
				return 1;
			}
			if (arrow == 1) {
				return 0;
			}
			if (arrow == 2) {
				return 2;
			}
		}
	}
}
void resetGame() {
	int scoreRec=0;
//
////	FILE* f = fopen("record.txt", "rt");
//	//fscanf(f, "%d", &scoreRec);
//	//fclose(f);
//
//	if (scoreRec < score) {
//		FILE* f = fopen("record.txt", "wt");
//		//printf("ping"); Sleep(1000);
//		fprintf(f, "%d\n", score);
//		fclose(f);
//	}


	flag = 1;
	obstacleCount = 0;
	currentTime = 0;
	score = 0;
	life = 1;
	eog = 0;
	rotatedStage = 0;
	playerInfo = 0;

	for (int i = 0; i < GBOARD_WIDTH; i++) {
		jumpInfoHorizon[i] = 0;
	}
	for (int i = 0; i < GBOARD_HEIGHT; i++) {
		jumpInfoVertical[i] = 0;
	}
}
void updateScore() {
	SetCurrentCursorPos(20, GBOARD_ORIGIN_Y - 4);
	printf("Score : %6d", score);
	SetCurrentCursorPos(20, GBOARD_ORIGIN_Y - 3);
	printf("Life : %6d", life);
	score += 1;
}