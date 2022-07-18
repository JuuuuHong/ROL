#include "header.h"
#include "main.h"






int main() /////////////////////////////////////////////////////////////////////////////////////////////////////////////////  �����Լ�
{
	//ranking();
	before_game();
	//game_done();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  �����Լ�





enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE
};
void setcolor(unsigned text) // ���� ���� 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}
void gotoxy(int x, int y) // ��ǥ�� ����
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void hidecursor() //Ŀ���� ����
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void fullscreen()	// ��üȭ�� (������ �ȵ� .............) 
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}




int updown_move() // �� �Ʒ� �����̱�
{

	UD_cursor_ret = 1;

	x = 78;
	y = 9;
	gotoxy(x, y);
	printf("��");
	while (1)
	{
		key = _getch();

		if (key == DOWN && UD_cursor_ret < 4)
		{
			UD_cursor_ret++;
			gotoxy(x, y);
			printf("��");
			y += 1;
			gotoxy(x, y);
			printf("��");
			cursor_sound();
		}
		else if (key == UP && UD_cursor_ret > 1)
		{
			UD_cursor_ret--;
			gotoxy(x, y);
			printf("��");
			y -= 1;
			gotoxy(x, y);
			printf("��");
			cursor_sound();
		}
		else if (key == SPACE)
		{
			select_sound();
			return UD_cursor_ret;
		}
	}
}
int leftright_move()	// ���� ������ ������
{
	x = 30;
	y = 12;
	LR_cursor_ret = 1;
	hidecursor();
	gotoxy(x, y);
	printf("������");
	while (1)
	{
		key = _getch();

		if (key == LEFT && LR_cursor_ret > 1)
		{
			LR_cursor_ret--;
			printf("\b\b\b\b\b\b\b\b\b\b");
			printf("            ");
			x -= 55;
			gotoxy(x, y);
			printf("������");
			cursor_sound();
		}
		else if (key == RIGHT && LR_cursor_ret < 2)
		{
			LR_cursor_ret++;
			printf("\b\b\b\b\b\b\b\b\b\b");
			printf("           ");
			x += 55;
			gotoxy(x, y);
			printf("������");
			cursor_sound();
		}
		else if (key == SPACE)
		{
			select_sound();
			return LR_cursor_ret;
		}
	}
}
int DFJK()
{
	while (1)
	{
		key = _getch();
		if (key == D)
		{
			returnvalue = D;
			return returnvalue;
		}
		else if (key == F)
		{
			returnvalue = F;
			return returnvalue;
		}
		else if (key == J)
		{
			returnvalue = J;
			return returnvalue;
		}
		else if (key == K)
		{
			returnvalue = K;
			return returnvalue;
		}
	}
}




int YN()	// ���� Y or N
{
	while (1)
	{
		key = _getch();
		if (key == YES)
		{
			returnvalue = 1;
			select_sound();
			return returnvalue;
		}
		else if (key == NO)
		{
			returnvalue = 2;
			select_sound();
			return returnvalue;
		}
	}
}
int quit()	// q�� ������
{
	while (1)
	{
		q = _getch();
		if (q == QUIT)
		{
			quit_ret = 1;
			select_sound();
			return quit_ret;
		}
	}
}
int space()	// �����̽���
{
	while (1)
	{
		spa = _getch();
		if (spa == SPACE)
		{
			space_ret = 1;
			select_sound();
			return space_ret;
		}
	}
}
int LR_Q()	// ���� ������ �����̰� q�� ������
{
	x = 30;
	y = 12;
	gotoxy(x, y);
	printf("������");
	while (1)
	{
		key = _getch();
		if (key == LEFT && LR_cursor_ret > 1)
		{
			LR_cursor_ret--;
			printf("\b\b\b\b\b\b\b\b\b\b");
			printf("            ");
			x -= 55;
			gotoxy(x, y);
			printf("������");
			cursor_sound();
		}
		else if (key == RIGHT && LR_cursor_ret < 2)
		{
			LR_cursor_ret++;
			printf("\b\b\b\b\b\b\b\b\b\b");
			printf("           ");
			x += 55;
			gotoxy(x, y);
			printf("������");
			cursor_sound();
		}
		else if (key == SPACE)
		{
			cursor_sound();
			return LR_cursor_ret;
		}
		else if (key == QUIT)
		{
			quit_ret = 1;
			select_sound();
			return  quit_ret;
		}
	}
}




void startscreen()  // ���� ȭ�� ��� 
{
	hidecursor();
	setcolor(WHITE);
	printf("\n\n\n\n\n\n\n\n");
	printf("                                       ######            ###           ##\n");
	printf("                                       ##   ##          ## ##          ##");
	printf("        1.���� \n");
	printf("                                       ##   ##         ##   ##         ##");
	printf("        2.������\n");
	printf("                                       ######          ##   ##         ##");
	printf("        3.���۹�\n");
	setcolor(WHITE);
	printf("                                       ## ##           ##   ##         ##");
	printf("        4.��ŷ\n");
	printf("                                       ##  ##           ## ##          ##\n");
	printf("                                       ##   ##           ###           ######\n");
	printf("\n\n\n");
	setcolor(BLUE);
	printf("                                       ��,�� : Ŀ���̵�");
	setcolor(RED);
	printf("     space : ����");
	setcolor(WHITE);
}
void informscreen() // ���� ȭ��
{
	hidecursor();
	printf("                                          ######            ###           ##\n");
	printf("                                          ##   ##          ## ##          ##\n");
	printf("                                          ##   ##         ##   ##         ##\n");
	printf("                                          ######          ##   ##         ##\n");
	printf("                                          ## ##           ##   ##         ##\n");
	printf("                                          ##  ##           ## ##          ##\n");
	printf("                                          ##   ##           ###           ######\n");
	printf("\n     ����Ű�� �������� �����̰� ������ �����̽���, ���� Ű�� �޼���D, F �������� J, K�� �ΰ� �÷��� �Ͻø� �˴ϴ�");
	printf("\n\n\n");
	printf("              ����������������������������������������    ����������������������������������������     ����������������������������������������     ����������������������������������������\n");
	printf("              ��      #####       ��    ��      #######     ��     ��        ####      ��     ��      ##   ##     ��\n");
	printf("              ��      ##  ##      ��    ��      ##          ��     ��          ##      ��     ��      ##  ##      ��\n");
	printf("              ��      ##   ##     ��    ��      ##          ��     ��          ##      ��     ��      ## ##       ��\n");
	printf("              ��      ##   ##     ��    ��      #####       ��     ��          ##      ��     ��      ####        ��\n");
	printf("              ��      ##   ##     ��    ��      ##          ��     ��      ##  ##      ��     ��      ## ##       ��\n");
	printf("              ��      ##  ##      ��    ��      ##          ��     ��      ##  ##      ��     ��      ##  ##      ��\n");
	printf("              ��      ####        ��    ��      ##          ��     ��       ####       ��     ��      ##   ##     ��\n");
	printf("              ����������������������������������������    ����������������������������������������     ����������������������������������������     ����������������������������������������\n");
	printf("  \n\n							q: ������");
}
void selectscreen()
{
	hidecursor();
	printf("                                          ######            ###           ##\n");
	printf("                                          ##   ##          ## ##          ##\n");
	printf("                                          ##   ##         ##   ##         ##\n");
	printf("                                          ######          ##   ##         ##\n");
	printf("                                          ## ##           ##   ##         ##\n");
	printf("                                          ##  ##           ## ##          ##\n");
	printf("                                          ##   ##           ###           ######\n");
	setcolor(RED);
	printf("												q: ���� ȭ������\n");
	setcolor(WHITE);
	printf("\n\n\n\n\n");
	printf("                   ������������������������������������������������������������                         ������������������������������������������������������������\n");
	printf("                   ��                            ��                         ��                            ��\n");
	printf("                   ��                            ��                         ��                            ��\n");
	printf("                   ��      ����: fade            ��                         ��       ����: force          ��\n");
	printf("                   ��                            ��                         ��                            ��\n");
	printf("                   ��      ��Ƽ��Ʈ: Alan walker ��                         ��       ��Ƽ��Ʈ: Alan walker��\n");
	printf("                   ��                            ��                         ��                            ��\n");
	printf("                   ��      ���̵�: �ڡڡڡ١�    ��                         ��       ���̵�:�ڡڡڡڡ�    ��\n");
	printf("                   ��                            ��                         ��                            ��\n");
	printf("                   ��                            ��                         ��                            ��\n");
	printf("                   ������������������������������������������������������������                         ������������������������������������������������������������");
}
void playscreen()
{

	printf("��������������������������������������������������������������������������������\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��                                      ����\n");
	printf("��                                      ��\n");
	printf("��                                      ��\n");
	printf("��������������������������������������������������������������������������������\n");
}
void done()	// ����ȭ��
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                                                     �����Ͻðڽ��ϱ�?\n\n\n\n");
	printf("                                                 Y: ����  N: ����ȭ������");
}
void ranking_screen() {
	printf("\n");
	printf("             ##      #####   ######  \n");
	printf("            ###     ##   ##  # ## #  \n");
	printf("             ##     #          ##    \n");
	printf("             ##      #####     ##    \n");
	printf("             ##          ##    ##    \n");
	printf("             ##     ##   ##    ##                                                                      q:������\n");
	printf("           ######    #####    ####   \n");
	printf("\n\n\n\n");
	printf("            ####    ##   ##  #####   \n");
	printf("           ##  ##   ###  ##   ## ##  \n");
	printf("               ##   #### ##   ##  ## \n");
	printf("             ###    ## ####   ##  ## \n");
	printf("            ##      ##  ###   ##  ## \n");
	printf("           ##  ##   ##   ##   ## ##  \n");
	printf("           ######   ##   ##  #####   \n");
	printf("\n\n\n\n");
	printf("            ####    ######   #####   \n");
	printf("           ##  ##    ##  ##   ## ##  \n");
	printf("               ##    ##  ##   ##  ## \n");
	printf("             ###     #####    ##  ## \n");
	printf("               ##    ## ##    ##  ## \n");
	printf("           ##  ##    ##  ##   ## ##  \n");
	printf("            ####    #### ##  #####   \n");
}
void game_done()
{
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("                                                        q: ������");
	printf("\n\n\n\n\n\n\n\n");
	printf("                                                  Your score is  %d", score);
	printf("\n\n\n");
}




void end_ranking() {
	gotoxy(50, 10);
	scanf("%s", printname);
	insert(printname, score);  // �Է� �޾Ƽ� ������ ���̽� ����
	system("cls");
}
void ranking() {
	view();
}




void ending() {
	printf("  ###                                   \n");
	printf(" ## ##                                  \n");
	printf(" ##       ####    ####   #  ###   ####  \n");
	printf("  ###    ##      ##  ##   ###    ##  ## \n");
	printf("    ##   ##      ##  ##   ##     ###### \n");
	printf(" ## ##   ##      ##  ##   ##     ##     \n");
	printf("  ###     ####    ####    ##      ####  \n");
}





void select_sound() {
	PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
}
void cursor_sound() {
	PlaySound(TEXT("select_sound.wav"), NULL, SND_ASYNC);
}
void fade() {
		PlaySound(TEXT("fade.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
void force() {
	PlaySound(TEXT("force.wav"), NULL, SND_ASYNC);
}




void gameplay(int map[][5])
{
	/*for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 4; j++) {
			switch (map[i][j]) {
			case 0:
				gotoxy(2 + 6 * j, 1 + i);
				printf("      ");
				break;
			case 1:
				gotoxy(2 + 6 * j, 1 + i);
				printf("����");
				break;
			}
		}
	}*/
	/*case 1:
		gotoxy(2, y);
		printf("%s", BLOCK1);
		break;
	case 2:
		gotoxy(2 , y);
		printf("%s", BLOCK2);
		break;
	case 3:
		gotoxy(2, y);
		printf("%s", BLOCK3);
		break;
	case 4:
		gotoxy(2 , y);
		printf("%s", BLOCK4);
		break;
	case 5:
		gotoxy(2, y);
		printf("%s", BLOCK5);
		break;
	case 6:
		gotoxy(2 , y);
		printf("%s", BLOCK6);
		break;
	case 7:
		gotoxy(2 , y);
		printf("%s", BLOCK7);
		break;
	case 8:
		gotoxy(2 , y);
		printf("%s", BLOCK8);
		break;
	case 9:
		gotoxy(2 , y);
		printf("%s", BLOCK9);
		break;
	case 10:
		gotoxy(2 , y);
		printf("%s", BLOCK10);
		break;
	case 11:
		gotoxy(2, y);
		printf("%s", BLOCK11);
		break;
	case 12:
		gotoxy(2, y);
		printf("%s", BLOCK12);
		break;
	case 13:
		gotoxy(2 , y);
		printf("%s", BLOCK13);
		break;
	case 14:
		gotoxy(2 , y);
		printf("%s", BLOCK14);
		break;
	case 15:
		gotoxy(2 , y);
		printf("%s", BLOCK15);
		break;
	}*/

	for (int i = 1; i < 26; i++) {
		for (int j = 1; j < 5; j++) {
			switch (map[i][j]) {
			case 0:
				gotoxy(j * 7, i);
				printf("%s", VOID);
				break;
			case 1:
				gotoxy(j * 7, i);
				printf("%s", BLOCK);
				break;
			}

		}
	}


}
void Setting(int map[][5], int* combo) {
	for (int i = 4; i > 0; i--) {
		for (int j = 25; j >= 0; j--) {
			if (i != 25) {
				map[j + 1][i] = map[j][i];
				map[j][i] = 0;
			}
		}

		if (map[26][i] == 1) {
			gotoxy(51, 20);
			printf("Miss         ");
			map[26][i] = 0;
			*combo = 0;
		}
	}

}
void spawnnote1(int map[][5]) {
	map[0][1] = 1;
}
void spawnnote2(int map[][5]) {
	map[0][2] = 1;
}
void spawnnote3(int map[][5]) {
	map[0][3] = 1;
}
void spawnnote4(int map[][5]) {
	map[0][4] = 1;
}
unsigned _stdcall Render(void* arg) {
	score = 0;

	while (1) 
	{
		gameplay(map);
		Setting(map, &combo);

		if (_kbhit() && GetAsyncKeyState(0x44) & 0x8000) {

			for (int i = 25; i >= 0; i--)
			{
				if (map[i][1] == 1)
				{
					if (i <= 24 && i >= 23) {
						gotoxy(51, 20);
						printf("Perfect!      ");
						combo++;
						score += 50;
						map[i][1] = 0;
						//break;
					}
					else if (i <= 22 && i >= 21) {
						gotoxy(51, 20);
						printf("GOOD!      ");
						combo++;
						score += 25;
						map[i][1] = 0;
						//break;
					}
					else {
						gotoxy(51, 20);
						printf("BAD!         ");
						combo = 0;
						score -= 20;
						//break;
					}
				}
			}

			_getch();

		}
		if (_kbhit() && GetAsyncKeyState(0x44) & 0x8000) {

			for (int i = 25; i >= 0; i--)
			{
				if (map[i][2] == 1)
				{
					if (i <= 24 && i >= 23) {
						gotoxy(51, 20);
						printf("Perfect!      ");
						combo++;
						score += 50;
						map[i][2] = 0;
						//break;
					}
					else if (i <= 22 && i >= 21) {
						gotoxy(51, 20);
						printf("GOOD!      ");
						combo++;
						score += 25;
						map[i][2] = 0;
						//break;
					}
					else {
						gotoxy(51, 20);
						printf("BAD!         ");
						combo = 0;
						score -= 20;
						//break;
					}
				}
			}

			_getch();

		}
		if (_kbhit() && GetAsyncKeyState(0x44) & 0x8000) {

			for (int i = 25; i >= 0; i--)
			{
				if (map[i][3] == 1)
				{
					if (i <= 24 && i >= 23) {
						gotoxy(51, 20);
						printf("Perfect!      ");
						combo++;
						score += 50;
						map[i][3] = 0;
						//break;
					}
					else if (i <= 22 && i >= 21) {
						gotoxy(51, 20);
						printf("GOOD!      ");
						combo++;
						score += 25;
						map[i][3] = 0;
						//break;
					}
					else {
						gotoxy(51, 20);
						printf("BAD!         ");
						combo = 0;
						score -= 20;
						//break;
					}
				}
			}

			_getch();

		}
		if (_kbhit() && GetAsyncKeyState(0x44) & 0x8000) {

			for (int i = 25; i >= 0; i--)
			{
				if (map[i][4] == 1)
				{
					if (i <= 24 && i >= 23) {
						gotoxy(51, 20);
						printf("Perfect!      ");
						combo++;
						score += 50;
						map[i][4] = 0;
						//break;
					}
					else if (i <= 22 && i >= 21) {
						gotoxy(51, 20);
						printf("GOOD!      ");
						combo++;
						score += 25;
						map[i][4] = 0;
						//break;
					}
					else {
						gotoxy(51, 20);
						printf("BAD!         ");
						combo = 0;
						score -= 20;
						//break;
					}
				}
			}

			_getch();

		}


		if (combo == 0) {
			gotoxy(51, 14);
			printf("                  ");
		}
		else {
			gotoxy(51, 14);
			printf(" %d combo !", combo);
		}


		gotoxy(50, 3);
		printf("    %d��             ", score);


		Sleep(45);

		if (ret_finish == 1)
		{
			_endthread();
		}
		
	}
}


void DropNote_fade() {
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	fade();
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);		// 1
	
	
	Sleep(625);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);		// 2
	
	
	Sleep(625);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);		// 3
	
	
	Sleep(625);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);		// 4
	
	
	Sleep(625);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);		// 5
	
	
	Sleep(625);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);		// 6
	
	
	Sleep(625);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);		// 7
	
	
	Sleep(625);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);		
	Sleep(330);
	spawnnote1(map);		// 8
	Sleep(650);


	spawnnote1(map);		// ���⼭���� 2���� �ϰ� 1234�ϴ°� 1
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(610);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(610);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(600);


	spawnnote1(map);
	spawnnote2(map);
	spawnnote3(map);
	Sleep(650);
	spawnnote1(map);
	spawnnote2(map);
	spawnnote3(map);
	Sleep(650);
	spawnnote1(map);
	spawnnote2(map);
	spawnnote3(map);
	Sleep(470);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(450);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);


	spawnnote1(map);		// ���⼭���� 2���� �ϰ� 1234�ϴ°� 1
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(275);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);


	Sleep(550);
	spawnnote1(map);	// ���⼭���� 2���� �ϰ� 1234�ϴ°� 1
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(500);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);


	Sleep(250);
	spawnnote1(map);
	Sleep(1300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1300);
	spawnnote1(map);
	spawnnote2(map);
	spawnnote3(map);
	Sleep(1400);
	spawnnote1(map);
	spawnnote2(map);
	spawnnote3(map);
	spawnnote4(map);


	Sleep(1350);
	spawnnote1(map);
	spawnnote2(map);
	spawnnote3(map);
	spawnnote4(map);
	Sleep(1300);
	spawnnote1(map);
	spawnnote2(map);
	spawnnote3(map);
	Sleep(1300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1300);
	spawnnote1(map);


	Sleep(1350);
	spawnnote1(map);	// ���⼭���� 2���� �ϰ� 1234�ϴ°� 1
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(530);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);


	Sleep(550);
	spawnnote1(map);	// ���⼭���� 2���� �ϰ� 1234�ϴ°� 1
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(530);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);


	Sleep(600);
	spawnnote1(map);
	spawnnote2(map);
	spawnnote3(map);
	spawnnote4(map);
	Sleep(325);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote1(map);///////////////////////////////////////////////


	Sleep(110);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(240);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(590);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(600);

	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);

	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(600);

	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);

	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(600);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(600);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(600);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(600);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);				// �׳� 2���� �ϴ°�
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(330);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(600);


	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(600);


	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(600);


	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(600);


	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(110);
	spawnnote2(map);
	Sleep(110);
	spawnnote3(map);
	Sleep(110);
	spawnnote4(map);


	Sleep(250);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(330);
	spawnnote1(map);
	Sleep(1850);

	ret_finish = 1;
	system("cls");
	PlaySound(NULL, 0, 0);
}
void DropNote_force()
{
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1000);
	spawnnote1(map);
	Sleep(50);
	force();
	Sleep(450);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(1100);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(1100);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(1125);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(1100);
	/*spawnnote1(map);
	spawnnote2(map);
	Sleep(1000);
	spawnnote1(map);
	Sleep(515);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(1100);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(1100);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(510);
	spawnnote1(map);
	Sleep(1130);
	spawnnote1(map);	//////////////////����

	
	Sleep(1125);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1200);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1200);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1200);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1200);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);


	Sleep(1125);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1200);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1200);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1200);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1200);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(515);
	spawnnote1(map);
	spawnnote2(map);



	Sleep(555);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);


	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);


	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);


	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);


	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);


	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);


	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);


	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);



	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(500);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(150);
	spawnnote1(map);
	Sleep(250);
	spawnnote1(map);
	Sleep(300);
	spawnnote1(map);
	Sleep(285);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(500);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(150);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(290);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(500);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(150);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(290);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(500);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(150);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(290);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(500);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(150);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(290);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(500);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(150);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(290);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(500);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(150);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(290);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(500);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(150);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(290);


	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(500);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(150);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(250);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(300);
	spawnnote1(map);
	spawnnote2(map);
	Sleep(1500);*/
	

	

	ret_finish = 1;
	system("cls");
	PlaySound(NULL, 0, 0);
}




int result()
{
	system("cls");
	gotoxy(0, 0);
	game_done();
	quit();
}



int before_game()
{
	SetConsoleTitle(TEXT("Rythm Of Legend"));
	fullscreen();
	x = 78;
	y = 9;
	startscreen();
	hidecursor();
	updown_move();
	


	while (quit_ret != 1)		// �ʱⰪ 0 / q������ 1�� �ٲ�
	{
		if (quit_ret == 3)
		{
			system("cls");
			/*for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 26; j++)
				{
					map[i][j] = 0;
				}
			}*/
			result();
			if (quit_ret == 1)
			{
				quit_ret = 2;
			}
		}
		if (quit_ret == 2)
		{
			UD_cursor_ret = 1;
			LR_cursor_ret = 1;
			returnvalue = 0;
			ret_finish = 0;
			combo = 0;
			score = 0;
			system("cls");
			gotoxy(0, 0);
			startscreen();
			updown_move();
		}
		if (UD_cursor_ret == 1)
		{		// ���� ������ �� 1
			system("cls");
			selectscreen();
			LR_Q();
			if (quit_ret == 1)
			{
				system("cls");
				quit_ret = 2;
			}
			else if (LR_cursor_ret == 1) {
				system("cls");
				ret_finish = 0;
				playscreen();
				_beginthreadex(NULL, 0, Render, 0, 0, NULL);
				DropNote_fade();
				quit_ret = 3;
			}
			else if (LR_cursor_ret == 2) {///////////////////////////////////////////////////////////�־ȵɱ� �־ȵɱ�
				system("cls");
				ret_finish = 0;
				playscreen();
				_beginthreadex(NULL, 0, Render, 0, 0, NULL);
				DropNote_force();
				quit_ret = 3;
			}////////////////////////////////////////////////////////////////////////////////////�׷��� �� �ȵ���
		}
		else if (UD_cursor_ret == 2)
		{		// ������ ������ �� 2
			system("cls");
			done();
			YN();
			if (returnvalue == 1)
			{
				system("cls");
				break;
			}
			else if (returnvalue == 2)
			{
				system("cls");
				quit_ret = 2;
			}
		}
		else if (UD_cursor_ret == 3)
		{		// ���� ������ �� 3
			system("cls");
			informscreen();
			quit();
			if (quit_ret == 1)
			{
				quit_ret = 2;
				system("cls");
			}
		}
		else if (UD_cursor_ret == 4) {
			system("cls");
			gotoxy(0, 0);
			view();
			quit();
			if (quit_ret == 1)
			{
				quit_ret = 2;
				system("cls");
			}
		}
	}
}

