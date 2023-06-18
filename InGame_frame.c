#include "InGame.h"
#include "Cursor.h"
#include "Character.h"
#include "Model.h"
#include "UI.h"
#include "Root.h"
#include<conio.h>
#pragma comment(lib,"winmm.lib")
//InGame 특별대우
int InGame() {

	int startButton= printStartScreen();

	if (startButton/* == SPACE*/)
		return PlayGame();
}
int PlayGame() {
	//dropPlayer to land
	dropPlayer();// 시작화면에서 지면에 살짝 떠있는 캐릭터가 땅에 떨어지며 게임 시작
	//player Location
	setCurrentPlayerPos(STARTING_POINT_WIDTH * 2, GBOARD_HEIGHT - 3);
	//remove cursor
	RemoveCursor();
	
	while (1) {
		//run the stage : game loop
		
		//
		while (rotatedStage < 4) {//stage 1,2,3,4
			while (1) {//looop for one stage
				//doMotion();
				if (eog == 0)//end of stage !=false
					shiftScreenLeft(); // stage keep moves
				if (eog == 0 && printObstacle() == 0) {//every obstacle came out
					eog = 1;
				}

				int type = detectCollision();//colliskonDetect ; every frame
				//updateScore();
				if (type != -1) {//detectCollision result -> positive
					if (life == 0) {
						//PlaySound(NULL, 0, 0);
						//return printGameOver();
						return 0;//printGameOver() dummy
					}

				}

				if (eog == 1) {//if game ends
					if (rotatedStage == 0)//// go to next stage : 4 stage version to move
						curPos.X += 2; //player location change
					else if (rotatedStage == 1)
						curPos.Y--; 
					else if (rotatedStage == 2)
						curPos.X -= 2; 
					else if (rotatedStage == 3)
						curPos.Y++;
					int tmp = JumpToNextStage(); // show animation that jump to next stage and return factor
					if (tmp == 1) {
						break;
					}
					else if (tmp == 2) {//JumpToNextStage()가 검사결과 2를 반환 : 마지막 스테이지->game loop 탈출, 종료
						return 0;
					}
				}
				currentTime++;
				Sleep(RATE);
			}
			system("cls");
			RemoveCursor();
			DrawGameBoard(rotatedStage);//draw new map land : for next stage
			eog = 0; // next stage will be start
			currentTime = 0; //set Timer 0
			obstacleCount = 0; //장애물 갯수 ( 맵 길이와 일맥상통)
			playerInfo = rotatedStage * 24; // turn the character model angle for next stage
			flag = 1;
		}
	}
}