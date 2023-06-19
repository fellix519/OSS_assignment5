#define _CRT_SECURE_NO_DEPRECATE
#include "InGame.h"
#include "Cursor.h"
#include "Character.h"
#include "Model.h"
#include "UI.h"
#include "Root.h"
#include<conio.h>
#pragma comment(lib,"winmm.lib")
#include<mmsystem.h>//p;aysound  �Լ� ���� ���
int PlayGame() {
	//�÷��̾� ��������
	//PlaySound(TEXT("emart_1.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���
	//_getch();

	//dropPlayer to land
	dropPlayer();
	//player Location
	setCurrentPlayerPos(STARTING_POINT_WIDTH * 2, GBOARD_HEIGHT - 3);
	RemoveCursor();
	while (rotatedStage < 4) {//4 stage to run
		while (1) {//loop for one stage
			doMotion(gameInfoByStage[rotatedStage][obstacleCount][1]);
			if (eog == 0)//end of stage !=false
				shiftScreenLeft();// stage keep moves
			if (eog == 0 && printObstacle() == 0) {//every obstacle 
				eog = 1;
			}

			int type = detectCollision();//colliskonDetect ; every frame
			updateScore();
			if (type != -1) {
				//detectCollision result -> positive
				if (life == 0) {
					//PlaySound(NULL, 0, 0);
					return printGameOver();
				}

			}

			if (eog == 1) {//if game ends
				if (rotatedStage == 0)///go to next stage 
					curPos.X += 2; //set player location for next stage
				else if (rotatedStage == 1)
					curPos.Y--;
				else if (rotatedStage == 2)
					curPos.X -= 2;
				else if (rotatedStage == 3)
					curPos.Y++;
				int tmp = JumpToNextStage(); //show animation that ump to next stage and return factor
				if (tmp == 1) {
					break;
				}
				else if (tmp == 2) { // JumpToNextStage() judge that it is last stage for the game -> quit the loop and terminate
					return 0;
				}
			}
			currentTime++;
			Sleep(RATE);
		}
		system("cls");
		RemoveCursor();
		DrawGameBoard(rotatedStage); // draw land of next stage
		eog = 0;  // initialize 
		currentTime = 0;
		obstacleCount = 0; // ��ֹ� ���� ���� 9 (�� ���̿� ����)
		playerInfo = rotatedStage * 24; //turn the character model angle for next stage
		flag = 1;
	}
}

//ĳ���� ���� �Լ�
int doMotion(int stage) {
	//int checkInfo = 1;
	//if (currentTime%2 == 0) {
	if (eog == 0) { //�����ؾ� �� ��ֹ��� ���� ������ �ÿ��� ĳ���Ͱ� ���ڸ��� �ֱ� ������ ĳ������ �ڸ��� ����� �����.
		DeleteCh(Character[playerInfo], curPos.X, curPos.Y);
	}
	else {//�����ؾ� �� ��ֹ��� ��� �����ߴٸ� ĳ���Ͱ� ������ �����ؾ��ϱ� ������ ĳ������ ���� �ڸ��� ����� �����.
		if (rotatedStage == 0)
			DeleteCh(Character[playerInfo], curPos.X - 2, curPos.Y);
		else if (rotatedStage == 1)
			DeleteCh(Character[playerInfo], curPos.X, curPos.Y + 1);
		else if (rotatedStage == 2)
			DeleteCh(Character[playerInfo], curPos.X + 2, curPos.Y);
		else if (rotatedStage == 3)
			DeleteCh(Character[playerInfo], curPos.X, curPos.Y - 1);
	}


	playerInfo++;
	if (playerInfo % 8 == 0) {
		playerInfo = rotatedStage * 24;
	}
	//���� �ٵ��� Ű �ߺ��Է� ����
	if (playerInfo % 24 == 0) {
		if (rotatedStage == 0)
			curPos.Y = GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 3;
		else if (rotatedStage == 1)
			curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - 8;
		else if (rotatedStage == 2)
			curPos.Y = GBOARD_ORIGIN_Y + 1;
		else if (rotatedStage == 3)
			curPos.X = GBOARD_ORIGIN_X + 2;
	}

	if (_kbhit()) {
		int tmp = 0;
		//  Ű �ñ�
		if (playerInfo >= 8 + 24 * rotatedStage) {
			_getch();
			return 0;
		}
		int kb = _getch();
		if (kb == SPACE) {
			if (currentTime < 5) {
				return 0;
			}
			if (rotatedStage % 2 == 0) {
				for (int i = 6; i < 14; i++) {
					if (gameBoardInfoHorizon[i] == rotatedStage * 8 + 4) {
						tmp = 1;
						break;
					}
				}

			}
			else {
				for (int i = 4; i < 12; i++) {
					if (gameBoardInfoVertical[i] == rotatedStage * 8 + 4) {
						tmp = 1;
						break;
					}
				}
			}
			if (tmp == 1)
				playerInfo = rotatedStage * 24 + 16;
			else {
				playerInfo = 8 + 24 * rotatedStage;
				tmp = 0;
			}

		}
	}

	if (playerInfo >= 8 + 24 * rotatedStage && playerInfo < 12 + 24 * rotatedStage) {
		if (rotatedStage == 0)
			curPos.Y -= 2;
		else if (rotatedStage == 1) {
			curPos.X -= 4;
		}
		else if (rotatedStage == 2)
			curPos.Y += 2;
		else if (rotatedStage == 3)
			curPos.X += 4;
	}
	else if (playerInfo >= 13 + 24 * rotatedStage && playerInfo < 16 + 24 * rotatedStage) {
		if (rotatedStage == 0) {
			curPos.Y += 2;
			if (curPos.Y > GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 3) {
				curPos.Y = GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 3;
			}
		}
		else if (rotatedStage == 1) {
			curPos.X += 4;
			if (curPos.X > GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - 8)
				curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - 8;
		}
		else if (rotatedStage == 2) {
			curPos.Y -= 2;
			if (curPos.Y < GBOARD_ORIGIN_Y + 4)
				curPos.Y = GBOARD_ORIGIN_Y + 4;
		}
		else if (rotatedStage == 3) {
			curPos.X -= 4;
			if (curPos.X < GBOARD_ORIGIN_X + 8)
				curPos.X = GBOARD_ORIGIN_X + 8;
		}
	}

	//detectCollision ����
	Showcharacter(Character[playerInfo], curPos.X, curPos.Y);

	return 0;
	//}
}
int detectCollision() {

	for (int py = 0; py < 3; py++) {
		for (int px = 0; px < 3; px++) {
			if (Character[playerInfo][py][px] != 0) {
				//�÷��̾� �迭�� �ڸ���� �ִ� ��ġ
				int playerX = curPos.X + px * 2; //curPos->�÷��̾� ��ġ
				int playerY = curPos.Y + py;

				if (rotatedStage == 0) {

					for (int tx = 0; tx < 10; tx++) { //(curPos.X - GBOARD_ORIGIN_X) / 2 + 2; tx++) {

					   //�ش� ���� �ȿ� ��ֹ��� ������
						int type = gameBoardInfoHorizon[tx];

						if (type != -1) {
							int jump = jumpInfoHorizon[tx]; //���� ����
							for (int oy = 0; oy < 5; oy++) {
								for (int ox = 0; ox < 5; ox++) {

									if (Model[type][oy][ox] == 0) {
										continue;
									}
									int obstacleX = GBOARD_ORIGIN_X + tx * 2 + ox * 2;
									int obstacleY = GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 5 + oy;
									//��ֹ� ���� �� �ɼ� �߰�
									if (jump >= 0) {
										obstacleY -= jumpArray[(jump - 1) % 16];
									}

									/*SetCurrentCursorPos(obstacleX, obstacleY);
									printf("%d", type); Sleep(10);*/

									if (playerX == obstacleX) {
										if (playerY == obstacleY) {
											if (type == 8 * rotatedStage + 5 && flag == 1) { //��Ʈ
												flag = 0;
												life++;
												gameBoardInfoHorizon[tx] += 2;
												//type -1 �̸� �浹ó�� ����
												type = -1;

												SetCurrentCursorPos(midX, midY);
												printf("����!"); Sleep(200);
												SetCurrentCursorPos(midX, midY);
												printf("     ");
											}
											else if (type == 8 * rotatedStage + 6 || type == 8 * rotatedStage + 7) {
												flag = 0;
												type = -1;
											}
											else if (flag == 1) {
												if (type == 8 * rotatedStage + 4 && flag == 1) { //����
													if (playerInfo >= 24 * rotatedStage + 16 && playerInfo < 24 * rotatedStage + 20) {
														type = -1;
														return type;
													}
												}
												flag = 0;
												life--;
												//�浹 �޼���
												SetCurrentCursorPos(midX, midY);
												printf("Oops!"); Sleep(1000);
												SetCurrentCursorPos(midX, midY);
												printf("     ");

											}
											return type;
										}
									}
								}
							}
						}
					}


				}

				else if (rotatedStage == 1) {
					for (int ty = 0; ty < 10; ty++) {
						//�ش� ���� �ȿ� ��ֹ��� ������
						int type = gameBoardInfoVertical[ty];
						if (type != -1) {
							int jump = jumpInfoVertical[ty];
							for (int oy = 0; oy < 5; oy++) {
								for (int ox = 0; ox < 5; ox++) {
									if (Model[type][oy][ox] == 0) {
										continue;
									}
									int obstacleX = GBOARD_ORIGIN_X + (GBOARD_WIDTH - 6) * 2 + ox * 2;
									int obstacleY = GBOARD_ORIGIN_Y + GBOARD_HEIGHT - ty + oy;
									if (jump >= 0) {
										obstacleX -= jumpArray[(jump - 1) % 16] * 2;
									}

									/*SetCurrentCursorPos(obstacleX, obstacleY);
									printf("%d", jump % 16); Sleep(10);*/
									if (playerX == obstacleX) {
										if (playerY == obstacleY) {
											if (type == 8 * rotatedStage + 5 && flag == 1) { //��Ʈ
												flag = 0;
												life++;
												gameBoardInfoVertical[ty] += 2;
												type = -1;

												SetCurrentCursorPos(midX, midY);
												printf("����!"); Sleep(200);
												SetCurrentCursorPos(midX, midY);
												printf("     ");
											}
											else if (type == 8 * rotatedStage + 6 || type == 8 * rotatedStage + 7) {
												type = -1;
											}
											else if (flag == 1) {
												if (type == 8 * rotatedStage + 4 && flag == 1) { //����
													if (playerInfo >= 24 * rotatedStage + 16 && playerInfo < 24 * rotatedStage + 20) {
														type = -1;
														flag = gameBoardInfoVertical[ty] += 2;
														return type;

													}
												}
												flag = 0;
												life--;
												//�浹 �޼���
												SetCurrentCursorPos(midX, midY);
												printf("Oops!"); Sleep(1000);
												SetCurrentCursorPos(midX, midY);
												printf("     ");

											}
											return type;
										}
									}

								}
							}
						}
					}
				}
				else if (rotatedStage == 2) {
					for (int tx = 0; tx < 10; tx++) {

						//�ش� ���� �ȿ� ��ֹ��� ������
						int type = gameBoardInfoHorizon[tx];
						if (type != -1) {
							int jump = jumpInfoHorizon[tx]; //���� ����

							for (int oy = 0; oy < 5; oy++) {
								for (int ox = 0; ox < 5; ox++) {

									if (Model[type][oy][ox] == 0) {
										continue;
									}

									int obstacleX = GBOARD_ORIGIN_X + GBOARD_WIDTH * 2 - tx * 2 + ox * 2;
									int obstacleY = GBOARD_ORIGIN_Y + oy + 1;

									if (jump >= 0) {
										obstacleY += jumpArray[(jump - 1) % 16];
									}
									/*SetCurrentCursorPos(obstacleX, obstacleY);
									printf("%d", jump % 16); Sleep(10);*/

									if (playerX == obstacleX) {
										if (playerY == obstacleY) {
											if (type == 8 * rotatedStage + 5 && flag == 1) { //��Ʈ
												flag = 0;
												life++;
												gameBoardInfoHorizon[tx] += 2;
												type = -1;
												SetCurrentCursorPos(midX, midY);
												printf("����!"); Sleep(200);
												SetCurrentCursorPos(midX, midY);
												printf("     ");
											}
											else if (type == 8 * rotatedStage + 6 || type == 8 * rotatedStage + 7) {
												type = -1;
											}
											else if (flag == 1) {
												if (type == 8 * rotatedStage + 4 && flag == 1) { //����
													if (playerInfo >= 24 * rotatedStage + 16 && playerInfo < 24 * rotatedStage + 20) {
														type = -1;
													}
												}
												else {
													flag = 0;
													life--;
													//�浹 �޼���
													SetCurrentCursorPos(midX, midY);
													printf("Oops!"); Sleep(1000);
													SetCurrentCursorPos(midX, midY);
													printf("     ");

												}
											}
											return type;
										}
									}
								}
							}
						}
					}
				}
				else if (rotatedStage == 3) {
					for (int ty = 0; ty < 10; ty++) {
						//�ش� ���� �ȿ� ��ֹ��� ������
						int type = gameBoardInfoVertical[ty];
						if (type != -1) {
							int jump = jumpInfoVertical[ty];
							for (int oy = 0; oy < 5; oy++) {
								for (int ox = 0; ox < 5; ox++) {
									if (Model[type][oy][ox] == 0) {
										continue;
									}
									int obstacleX = GBOARD_ORIGIN_X + ox * 2;
									int obstacleY = GBOARD_ORIGIN_Y + ty + oy;
									if (jump >= 0) {
										obstacleX += jumpArray[(jump - 1) % 16] * 2 + 2;
									}
									/*SetCurrentCursorPos(obstacleX, obstacleY);
									printf("%d", obstacleY);
									SetCurrentCursorPos(playerX, playerY);
									printf("%d", playerY); Sleep(10);*/
									if (playerX == obstacleX) {
										if (playerY == obstacleY) {
											if (type == 8 * rotatedStage + 5 && flag == 1) { //��Ʈ
												flag = 0;
												life++;
												gameBoardInfoVertical[ty] += 2;
												type = -1;

												SetCurrentCursorPos(midX, midY);
												printf("����!"); Sleep(200);
												SetCurrentCursorPos(midX, midY);
												printf("     ");
											}
											else if (type == 8 * rotatedStage + 6 || type == 8 * rotatedStage + 7) {
												type = -1;
											}
											else if (flag == 1) {
												if (type == 8 * rotatedStage + 4 && flag == 1) { //����
													if (playerInfo >= 24 * rotatedStage + 16 && playerInfo < 24 * rotatedStage + 20) {
														type = -1;
														flag = gameBoardInfoVertical[ty] += 2;
														return type;

													}
												}
												flag = 0;
												life--;
												//�浹 �޼���
												SetCurrentCursorPos(midX, midY);
												printf("Oops!"); Sleep(1000);
												SetCurrentCursorPos(midX, midY);
												printf("     ");

											}

											return type;

										}
									}
								}
							}
						}
					}

				}
			}
		}
	}
	flag = 1;
	return -1;
}

//��ֹ� ���� �Լ�
void shiftScreenLeft() {
	if (rotatedStage % 2 == 0) {
		//���� ���� ������ ���� �ٸ� deleteObstacle �Լ� ����
		if (jumpInfoHorizon[0] >= 0 && jumpArray[jumpInfoHorizon[0] % 16] > 0) {
			deleteObstacle(gameBoardInfoHorizon[0], 0, jumpArray[(jumpInfoHorizon[0] - 1) % 16]); //�� ��ֹ��� �ֱ� ������ ����
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
			deleteObstacle(gameBoardInfoVertical[0], 0, jumpArray[(jumpInfoVertical[0] - 1) % 16]); //�� ��ֹ��� �ֱ� ������ ����
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
			//��ֹ� Ÿ��
			int type = gameBoardInfoHorizon[tx];
			//���� ����
			int jump = jumpInfoHorizon[tx];
			if (type >= 100) {
				CreateWall();
				return 0;
			}
			else if (type != -1) {
				if (rotatedStage == 0) {
					if (jump >= 0) {
						//��ֹ��� �����ؾ��һ�Ȳ�̸�
						jumpInfoHorizon[tx]++;
						ShowBlock(Model[type], GBOARD_ORIGIN_X + tx * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 5 - jumpArray[jump % 16]);
					}
					else {
						ShowBlock(Model[type], GBOARD_ORIGIN_X + tx * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 5);
					}
				}
				else if (rotatedStage == 2) {
					if (jump >= 0) {
						//��ֹ��� �����ؾ��һ�Ȳ�̸�
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
						//��ֹ��� �����ؾ��һ�Ȳ�̸�
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
						//��ֹ��� �����ؾ��һ�Ȳ�̸�
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
					//������ ���۵����� ���� if �ƴϸ� else
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

// ��ũ�� ���� ���� �Լ�
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

//UI ���� �Լ�
void printEndingScreen() {
	system("cls");
	//PlaySound(TEXT("Endding.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���

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
	int scoreRec;

	FILE* f = fopen("record.txt", "rt");
	fscanf(f, "%d", &scoreRec);
	fclose(f);

	if (scoreRec < score) {
		FILE* f = fopen("record.txt", "wt");
		//printf("ping"); Sleep(1000);
		fprintf(f, "%d\n", score);
		fclose(f);
	}


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

//�ʵ� ���� �Լ�
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
	//ĳ���� ��ġ�� ���� ���ܵΰ� 4ĭ �տ� �ִ��� Ȯ��
	//���� �׷��� ���� ��� �ϸ鼭 ���� 90�� ȸ���� ĳ���� ��� �����
	//���� �������� ����
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
	int* p = NULL;
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
			printf("��");
		}
		break;
	case 1:
		RATE = 30;
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH - 1) * 2, GBOARD_ORIGIN_Y + i);
			printf("��");
		}
		break;
	case 2:
		RATE = 25;
		for (int i = 0; i < GBOARD_WIDTH; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + i * 2, GBOARD_ORIGIN_Y);
			printf("��");
		}
		break;
	case 3:
		RATE = 20;
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + i);
			printf("��");
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
			printf("��");
		}
		break;
	case 1:
		for (int i = 0; i < GBOARD_WIDTH; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + i * 2, GBOARD_ORIGIN_Y);
			printf("��");
		}
		break;
	case 2:
		for (int i = 0; i < GBOARD_HEIGHT; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + GBOARD_HEIGHT - i - 1);
			printf("��");
		}
		break;
	case 3:
		for (int i = 0; i < GBOARD_WIDTH - 4; i++) {
			SetCurrentCursorPos(GBOARD_ORIGIN_X + (i + 4) * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
			printf("��");
		}
		break;
	default:
		break;
	}
}

//InGame Ư�����
int InGame() {

	int startButton = printStartScreen();

	if (startButton/* == SPACE*/)
		return PlayGame();
}

//��Ÿ �Լ�
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