#include "InGame.h"
#include "Cursor.h"
#include "Character.h"
#include "Model.h"
#include "UI.h"
#include "Root.h"
#include<conio.h>
#pragma comment(lib,"winmm.lib")
//InGame Ư�����
int InGame() {

	int startButton = printStartScreen();

	if (startButton/* == SPACE*/)
		return PlayGame();
}
int PlayGame() {
	
}