#include "UI.h"
#include "Cursor.h"

void setFullScreen() { //ū ȭ��
	char str[] = "mode con cols=192 lines=54";
	system(str);
}
void alignCenter(const char* str, int posY) { // ���� ��� ����
	int len = strlen(str);

	int posX = midX - len / 2;
	SetCurrentCursorPos(posX, posY);
	printf("%s", str);

}
int printStartTitle() { //����ȭ�� ���

	setFullScreen();
	RemoveCursor();
	int kb;
	int indicator = 0;
	PlaySound(TEXT("Pokemon_OG.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���)
	char chat1[] = "  Game Start";
	char chat1_indicated[] = "��Game Start";
	char chat2[] = "  Record";
	char chat2_indicated[] = "��Record";
	char chat3[] = "  Quit Game";
	char chat3_indicated[] = "��Quit Game";

	while (1) {
		alignCenter("�����̴� �����̾�!", midY - 2);
		if (indicator == 0) { // GameStart�� ����Ű�� ���� ��
			alignCenter(chat1_indicated, midY);
			alignCenter(chat2, midY + 2);
			alignCenter(chat3, midY + 4);
		}
		else if (indicator == 1) { //Record�� ����Ű�� ���� ��
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
			if (kb == DOWN) { //Down �� 
				indicator++;
				if (indicator > 2) {
					indicator = 2;
				}
			}
			if (kb == UP) { // UP ��
				indicator--;
				if (indicator < 0) {
					indicator = 0;
				}
			}
		}
		else if (kb == SPACE || kb == ENTER) { //Enter Ŭ�� ��

			if (indicator == 0) { // ����Ű�� �ִ� ��ư�� ���� �ٸ� �Լ� ����
				showOpeningScreen();
				return 0;
			}
			if (indicator == 1) {
				showRecord();
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
	alignCenter("�����̴� �Ͼ��", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("  \"�ʹ� �����....���õ��� �� �̷��� ��������?\"  ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	alignCenter("  \"�� ����...����?\"  ", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();

	system("cls");
	system("cls");
	alignCenter("�����̴� �ð踦 �ô�", midY);
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
	alignCenter("�ư� �׳� �޷�!!!!", midY);
	alignCenter("Press Any Key", midY + 7);
	_getch();
	system("cls");

	alignCenter("�١ڡ١ڡ١ڿ����̰� �ƴ϶�� ������ ���� ����!!�١ڡ١ڡ١�", midY - 4);
	alignCenter("                                           ������ �Ҹ� �����̵� ���� ���� ����", midY - 2);
	alignCenter("         ������������������������", midY - 1);
	alignCenter("�� S P A C E��", midY);
	alignCenter("         ������������������������", midY + 1);
	alignCenter("�̰ɷ� ���� �ذ� �����ϴ�!!", midY + 3);
	alignCenter("�׳� Ÿ�ֿ̹� �°� SPACE�� ������!!", midY + 5);
	alignCenter("Press Any Key", midY + 7);
	_getch();
}
void showRecord() {

	FILE* f = fopen("record.txt", "r");

	char stage1Score[10];
	char stage1Record[20] = "Stage 1 : ";

	fscanf(f, "%s", stage1Score);
	strcat(stage1Record, stage1Score);

	system("cls");
	alignCenter("RECORD", midY - 4);
	alignCenter(stage1Record, midY - 2);
	alignCenter("Press Any Key...(DEL to reset record)", midY + 2);

	fclose(f);

	int kb;
	kb = getch();
	if (kb == 224) {
		kb = getch();
		if (kb == DEL || kb == 83) {
			if (ResetRecord()) {
				FILE* f = fopen("record.txt", "w");

				fputs("0\n", f);

				fclose(f);

				alignCenter("Deleted completely", midY - 4);
			}
		}
	}
}
int ResetRecord() {
	int kb;
	int indicator = 0;

	char chat1[] = "  Y";
	char chat1_indicated[] = "��Y";
	char chat2[] = "  N";
	char chat2_indicated[] = "��N";

	system("cls");
	while (1) {
		if (indicator == 0) {
			alignCenter("Are you sure to reset record", midY - 2);
			alignCenter(chat1_indicated, midY);
			alignCenter(chat2, midY + 2);
		}
		else if (indicator == 1) {
			alignCenter("Are you sure to reset record", midY - 2);
			alignCenter(chat1, midY);
			alignCenter(chat2_indicated, midY + 2);
		}

		kb = _getch();
		if (kb == 224) {
			kb = _getch();
			if (kb == DOWN) {
				indicator = 1;
			}
			if (kb == UP) {
				indicator = 0;
			}
		}
		else if (kb == SPACE || kb == ENTER) {
			if (indicator == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		system("cls");
	}
	return 0;
}