#include "InGame.h"
#include "Cursor.h"
#include "Character.h"
#include "Model.h"
#include "UI.h"
#include "Root.h"

//캐릭터 관련 함수

int detectCollision() {

	for (int py = 0; py < 3; py++) {
		for (int px = 0; px < 3; px++) {
			if (Character[playerInfo][py][px] != 0) {
				//플레이어 배열이 자리잡고 있는 위치
				int playerX = curPos.X + px * 2; //curPos->플레이어 위치
				int playerY = curPos.Y + py;

				if (rotatedStage == 0) {

					for (int tx = 0; tx < 10; tx++) { //(curPos.X - GBOARD_ORIGIN_X) / 2 + 2; tx++) {

					   //해당 범위 안에 장애물이 있으면
						int type = gameBoardInfoHorizon[tx];

						if (type != -1) {
							int jump = jumpInfoHorizon[tx]; //점프 변수
							for (int oy = 0; oy < 5; oy++) {
								for (int ox = 0; ox < 5; ox++) {

									if (Model[type][oy][ox] == 0) {
										continue;
									}
									int obstacleX = GBOARD_ORIGIN_X + tx * 2 + ox * 2;
									int obstacleY = GBOARD_ORIGIN_Y + GBOARD_HEIGHT - 5 + oy;
									//장애물 점프 시 옵션 추가
									if (jump >= 0) {
										obstacleY -= jumpArray[(jump - 1) % 16];
									}

									/*SetCurrentCursorPos(obstacleX, obstacleY);
									printf("%d", type); Sleep(10);*/

									if (playerX == obstacleX) {
										if (playerY == obstacleY) {
											if (type == 8 * rotatedStage + 5 && flag == 1) { //하트
												flag = 0;
												life++;
												gameBoardInfoHorizon[tx] += 2;
												//type -1 이면 충돌처리 안함
												type = -1;

												SetCurrentCursorPos(midX, midY);
												printf("충전!"); Sleep(200);
												SetCurrentCursorPos(midX, midY);
												printf("     ");
											}
											else if (type == 8 * rotatedStage + 6 || type == 8 * rotatedStage + 7) {
												flag = 0;
												type = -1;
											}
											else if (flag == 1) {
												if (type == 8 * rotatedStage + 4 && flag == 1) { //행인
													if (playerInfo >= 24 * rotatedStage + 16 && playerInfo < 24 * rotatedStage + 20) {
														type = -1;
														return type;
													}
												}
												flag = 0;
												life--;
												//충돌 메세지
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
						//해당 범위 안에 장애물이 있으면
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
											if (type == 8 * rotatedStage + 5 && flag == 1) { //하트
												flag = 0;
												life++;
												gameBoardInfoVertical[ty] += 2;
												type = -1;

												SetCurrentCursorPos(midX, midY);
												printf("충전!"); Sleep(200);
												SetCurrentCursorPos(midX, midY);
												printf("     ");
											}
											else if (type == 8 * rotatedStage + 6 || type == 8 * rotatedStage + 7) {
												type = -1;
											}
											else if (flag == 1) {
												if (type == 8 * rotatedStage + 4 && flag == 1) { //행인
													if (playerInfo >= 24 * rotatedStage + 16 && playerInfo < 24 * rotatedStage + 20) {
														type = -1;
														flag = gameBoardInfoVertical[ty] += 2;
														return type;

													}
												}
												flag = 0;
												life--;
												//충돌 메세지
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

						//해당 범위 안에 장애물이 있으면
						int type = gameBoardInfoHorizon[tx];
						if (type != -1) {
							int jump = jumpInfoHorizon[tx]; //점프 변수

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
											if (type == 8 * rotatedStage + 5 && flag == 1) { //하트
												flag = 0;
												life++;
												gameBoardInfoHorizon[tx] += 2;
												type = -1;
												SetCurrentCursorPos(midX, midY);
												printf("충전!"); Sleep(200);
												SetCurrentCursorPos(midX, midY);
												printf("     ");
											}
											else if (type == 8 * rotatedStage + 6 || type == 8 * rotatedStage + 7) {
												type = -1;
											}
											else if (flag == 1) {
												if (type == 8 * rotatedStage + 4 && flag == 1) { //행인
													if (playerInfo >= 24 * rotatedStage + 16 && playerInfo < 24 * rotatedStage + 20) {
														type = -1;
													}
												}
												else {
													flag = 0;
													life--;
													//충돌 메세지
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
						//해당 범위 안에 장애물이 있으면
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
											if (type == 8 * rotatedStage + 5 && flag == 1) { //하트
												flag = 0;
												life++;
												gameBoardInfoVertical[ty] += 2;
												type = -1;

												SetCurrentCursorPos(midX, midY);
												printf("충전!"); Sleep(200);
												SetCurrentCursorPos(midX, midY);
												printf("     ");
											}
											else if (type == 8 * rotatedStage + 6 || type == 8 * rotatedStage + 7) {
												type = -1;
											}
											else if (flag == 1) {
												if (type == 8 * rotatedStage + 4 && flag == 1) { //행인
													if (playerInfo >= 24 * rotatedStage + 16 && playerInfo < 24 * rotatedStage + 20) {
														type = -1;
														flag = gameBoardInfoVertical[ty] += 2;
														return type;

													}
												}
												flag = 0;
												life--;
												//충돌 메세지
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
int doMotion(int stage) {
	//int checkInfo = 1;
	//if (currentTime%2 == 0) {
	if (eog == 0) { //출현해야 할 장애물이 아직 남았을 시에는 캐릭터가 제자리에 있기 때문에 캐릭터의 자리의 모습을 지운다.
		DeleteCh(Character[playerInfo], curPos.X, curPos.Y);
	}
	else {//출현해야 할 장애물이 모두 출현했다면 캐릭터가 앞으로 전진해야하기 때문에 캐릭터의 원래 자리의 모습을 지운다.
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
	//벽에 붙도록 키 중복입력 방지
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
		//  키 씹기
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

	//detectCollision 삽입
	Showcharacter(Character[playerInfo], curPos.X, curPos.Y);

	return 0;
	//}
}