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
	PlaySound(TEXT("Endding.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���

	system("cls");
	alignCenter(" \"��...�ȵ�..15��....15�и� �����ٸ�...\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" ������ : \"���� �л��� ���� �η� FA ó�� �� �����Դϴ�. ���� �������� ������ �����ŵ� �˴ϴ�.\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"������ ����...!!! �ѹ���...�ѹ��� ���ּ���!!!! �ȵſ�Ф�\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"�ȵ�....!\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"........\" ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" ������ �帣�� �� ��. Ŀư ���̷� ���� ���´�. ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"�� ��¥�� �ƴϿ���... ���� �����̾�..", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter(" \"���� �б� �� �غ��ؾ� �ڴ�. ������ �����?", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("�����̴� �ð踦 �ô�", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("11�� ���� ����Ű�� �ð�. ���� ���� ������ 1����, 9�ô�.", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	_getch();
}
int printGameOver() {

	char msg1[] = "  Play Again";
	char msg1_2[] = "��Play Again";
	char msg2[] = "  Go to Start Page";
	char msg2_2[] = "��Go to Start Page";
	char msg3[] = "  Quit Game";
	char msg3_2[] = "��Quit Game";
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
			if (select == DOWN) { //Down �� 
				arrow++;
				if (arrow > 2) {
					arrow = 2;
				}
			}
			if (select == UP) { // UP ��
				arrow--;
				if (arrow < 0) {
					arrow = 0;
				}
			}
		}
		else if (select == SPACE || select == ENTER) { //Enter Ŭ�� ��
			resetGame();

			if (arrow == 0) { // ����Ű�� �ִ� ��ư�� ���� �ٸ� �Լ� ����
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