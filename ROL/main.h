////////////////////////////////////// define



#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32
#define QUIT 113
#define YES 121
#define NO 110
#define D 100
#define F 102
#define J 106
#define K 107
#define BLOCK "����  "
#define VOID "      "
#define BLOCK1 "����                                 "
#define BLOCK2 "           ����                      "
#define BLOCK3 "                      ����           "
#define BLOCK4 "                                 ����"
#define BLOCK5 "����     ����                      "
#define BLOCK6 "����                ����           "
#define BLOCK7 "����                           ����"
#define BLOCK8 "           ����     ����           "
#define BLOCK9 "           ����                ����"
#define BLOCK10 "                      ����     ����"
#define BLOCK11 "����     ����     ����           "
#define BLOCK12 "           ����     ����     ����"
#define BLOCK13 "����                ����     ����"
#define BLOCK14 "����     ����                ����"
#define BLOCK15 "����     ����     ����     ����"

////////////////////////////////////////  ����


int x, y;
int UD_cursor_ret = 1;
int LR_cursor_ret = 1;
int returnvalue = 0;
char q = 0;
char spa;
char key;
int quit_ret = 0;
int space_ret = 0;
char name[21];
int score;
char printname[21];
int printscore;
int map[26][5] = { 0 };
int combo = 0;
int ret_finish = 0;
char c;

///////////////////////////////////////  �Լ�

void startscreen();				// ����ȭ�� ���
void informscreen();			// �ȳ�ȭ�� ���
void setcolor(unsigned text);	// ���� ���ϱ�
void hidecursor();				// Ŀ�� ����
int updown_move();				// ����Ű�� ������
int quit();						// ������ ��ư
int space();					// �����̽� ��ư
void selectscreen();			// �� ���� ��ư
int leftright_move();			// ����Ű�� ������
int LR_Q();						// ������ �����̽� ����Ű «��
void done();					// ������
int YN();						//  YES or NO
void select_sound();			// ����Ű ȿ���� ���	
void fade();					// fade
void force();					// bangbangbang
void cursor_sound();			// space�� ����
void playscreen();				// ���� ȭ��
void fullscreen();				// ��üȭ��
int before_game();				// ���� �� ��� ��
void ranking_screen();		// ��ŷ ȭ��
void gameplay();
void spawnnote1();
void spawnnote2();
void spawnnote3();
void spawnnote4();
void DropNote_fade();
void DropNote_force();
void Setting();
void game_done();
int result();




int DFJK();						// DFJK �Է� ����
void view();					// �����ͺ��̽��κ��� �� ������
void insert();					// �����ͺ��̽��� �� ���� �ֱ�
void ranking();					// ���� �ƿ� ��
void ending();					// ��� ȭ��