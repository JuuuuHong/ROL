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
#define BLOCK "■■■  "
#define VOID "      "
#define BLOCK1 "■■■                                 "
#define BLOCK2 "           ■■■                      "
#define BLOCK3 "                      ■■■           "
#define BLOCK4 "                                 ■■■"
#define BLOCK5 "■■■     ■■■                      "
#define BLOCK6 "■■■                ■■■           "
#define BLOCK7 "■■■                           ■■■"
#define BLOCK8 "           ■■■     ■■■           "
#define BLOCK9 "           ■■■                ■■■"
#define BLOCK10 "                      ■■■     ■■■"
#define BLOCK11 "■■■     ■■■     ■■■           "
#define BLOCK12 "           ■■■     ■■■     ■■■"
#define BLOCK13 "■■■                ■■■     ■■■"
#define BLOCK14 "■■■     ■■■                ■■■"
#define BLOCK15 "■■■     ■■■     ■■■     ■■■"

////////////////////////////////////////  변수


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

///////////////////////////////////////  함수

void startscreen();				// 시작화면 출력
void informscreen();			// 안내화면 출력
void setcolor(unsigned text);	// 색깔 정하기
void hidecursor();				// 커서 숨김
int updown_move();				// 방향키로 움직임
int quit();						// 나가기 버튼
int space();					// 스페이스 버튼
void selectscreen();			// 곡 선택 버튼
int leftright_move();			// 방향키로 움직임
int LR_Q();						// 나가기 스페이스 방향키 짬뽕
void done();					// 끝내기
int YN();						//  YES or NO
void select_sound();			// 방향키 효과음 재생	
void fade();					// fade
void force();					// bangbangbang
void cursor_sound();			// space바 음향
void playscreen();				// 게임 화면
void fullscreen();				// 전체화면
int before_game();				// 게임 전 모든 것
void ranking_screen();		// 랭킹 화면
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




int DFJK();						// DFJK 입력 받음
void view();					// 데이터베이스로부터 값 빼오기
void insert();					// 데이터베이스에 값 집어 넣기
void ranking();					// 게임 아예 끝
void ending();					// 결과 화면