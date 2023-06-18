#include "UI.h"
#include "Cursor.h"

void setFullScreen() { //큰 화면
	char str[] = "mode con cols=192 lines=54";
	system(str);
}
void alignCenter(const char* str, int posY) { // 문장 가운데 정렬
	int len = strlen(str);

	int posX = midX - len / 2;
	SetCurrentCursorPos(posX, posY);
	printf("%s", str);

}
int printStartTitle() { //시작화면 출력

	setFullScreen();
	RemoveCursor();
	int kb;
	int indicator = 0;
	PlaySound(TEXT("Pokemon_OG.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생)
	char chat1[] = "  Game Start";
	char chat1_indicated[] = "▶Game Start";
	char chat2[] = "  Record";
	char chat2_indicated[] = "▶Record";
	char chat3[] = "  Quit Game";
	char chat3_indicated[] = "▶Quit Game";

	while (1) {
		alignCenter("수현이는 지각이야!", midY - 2);
		if (indicator == 0) { // GameStart를 가리키고 있을 때
			alignCenter(chat1_indicated, midY);
			alignCenter(chat2, midY + 2);
			alignCenter(chat3, midY + 4);
		}
		else if (indicator == 1) { //Record를 가리키고 있을 때
			alignCenter(chat1, midY);
			alignCenter(chat2_indicated, midY + 2);
			alignCenter(chat3, midY + 4);
		}
		else {
			alignCenter(chat1, midY);
			alignCenter(chat2, midY + 2);
			alignCenter(chat3_indicated, midY + 4);
		}
		RemoveCursor();

		kb = _getch();
		if (kb == 224) {
			kb = _getch();
			if (kb == DOWN) { //Down 시 
				indicator++;
				if (indicator > 2) {
					indicator = 2;
				}
			}
			if (kb == UP) { // UP 시
				indicator--;
				if (indicator < 0) {
					indicator = 0;
				}
			}
		}
		else if (kb == SPACE || kb == ENTER) { //Enter 클릭 시

			if (indicator == 0) { // 가리키고 있는 버튼에 따라 다른 함수 실행
				showOpeningScreen();
				return 0;
			}
			if (indicator == 1) {
				//showRecord();
			}
			if (indicator == 2) {
				return 2;
			}
		}
		system("cls");
	}
}

void showOpeningScreen() {
	system("cls");
	alignCenter("수현이는 일어났다", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("  \"너무 잘잤다....오늘따라 왜 이렇게 개운하지?\"  ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("  \"이 느낌...설마?\"  ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	system("cls");
	alignCenter("수현이는 시계를 봤다", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("  \"......\"  ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("  \"..............\"  ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	system("cls");
	alignCenter("됐고 그냥 달려!!!!", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();
	system("cls");

	alignCenter("☆★☆★☆★원숭이가 아니라면 누구라도 이해 가능!!☆★☆★☆★", midY - 4);
	alignCenter("                                           ㄴ무슨 소리 원숭이도 이해 가능 ㄱㅡ", midY - 2);
	alignCenter("         ┌──────────┐", midY - 1);
	alignCenter("│ S P A C E│", midY);
	alignCenter("         └──────────┘", midY + 1);
	alignCenter("이걸로 전부 해결 가능하다!!", midY + 3);
	alignCenter("그냥 타이밍에 맞게 SPACE만 누르자!!", midY + 5);
	alignCenter("Press Any Key", midY + 7);
	_getch();
}
