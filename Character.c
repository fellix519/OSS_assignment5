#include "Cursor.h"
#include "Character.h"
void Showcharacter(char blockInfo[3][3], int x1, int y1) {//x1,y1->
   //COORD curPos = GetCurrentCursorPos();

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			SetCurrentCursorPos(x1 + x * 2, y1 + y);

			if (blockInfo[y][x] == 1) {
				printf("¡Ü");
			}
			else if (blockInfo[y][x] == 2) {
				printf("¦¶");
			}
			else if (blockInfo[y][x] == 21) {
				printf("¦²");
			}
			else if (blockInfo[y][x] == 22) {
				printf("¦µ");
			}
			else if (blockInfo[y][x] == 23) {
				printf("¦´");
			}
			else if (blockInfo[y][x] == 24) {
				printf("¦³");
			}
			else if (blockInfo[y][x] == 31) {
				printf("¡ü");
			}
			else if (blockInfo[y][x] == 101) {
				printf("¥¢");
			}
			else if (blockInfo[y][x] == 32) {
				printf("£¼");
			}
			else if (blockInfo[y][x] == 102) {
				printf("¡ë");
			}
			else if (blockInfo[y][x] == 33) {
				printf("¡ý");
			}
			else if (blockInfo[y][x] == 34) {
				printf("£¾");
			}

			else if (blockInfo[y][x] == 5) {
				printf("¥ï");
			}
			else if (blockInfo[y][x] == 51) {
				printf("¢´");
			}
			else if (blockInfo[y][x] == 8) {
				printf("¦­");
			}
			else if (blockInfo[y][x] == 81) {
				printf("¦¯");
			}
			else if (blockInfo[y][x] == 82) {
				printf("¦°");
			}
			else if (blockInfo[y][x] == 9) {
				printf("¦¬");
			}
			else if (blockInfo[y][x] == 91) {
				printf("¦®");
			}
			else if (blockInfo[y][x] == 92) {
				printf("¦±");
			}
		}
	}
	//SetCurrentCursorPos(curPos.X, curPos.Y);
	//SetCurrentCursorPos(curPos.X, curPos.Y);
}

void DeleteCh(char blockInfo[3][3], int x1, int y1) {

	//COORD curPos = GetCurrentCursorPos();

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			//SetCurrentCursorPos(curPos.X + x * 2, curPos.Y + y);
			SetCurrentCursorPos(x1 + x * 2, y1 + y);
			if (blockInfo[y][x] != 0) printf("  ");
		}
	}
	//SetCurrentCursorPos(curPos.X, curPos.Y);
}