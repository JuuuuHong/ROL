#include "header.h"

MYSQL* conn; //mysql과의 커넥션을 잡는데 지속적으로 사용되는 변수
MYSQL_RES* res; //쿼리문에 대한 result 값을 받는 변수
MYSQL_ROW row; //쿼리문에 대한 실제 데이터 값들 저장 변수

char* server = "localhost"; //MySQL 서버의 경로 -- localhost = 본인 컴퓨터
char* user = "root"; //MySQL 로그인 아이디, Default value = root
char* password = "158pk158."; //MySQL 로그인 할 때 쓰이는 password 값
char* database = "rankdb"; //Database 이름을 저장

void insert(char name[15], int point){
	char query[255]; //SQL Query 저장 변수

	conn = mysql_init(NULL); //conn 변수 초기화
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) { //Connect to database;
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(query, "insert into ranking values('%s',%d);", name, point); //query 변수에 insert SQL문 저장
	mysql_query(conn, query); //query 날리기

	mysql_close(conn); //연결 해제
}

void view() {
	char query[255]; //SQL Query 저장 변수

	conn = mysql_init(NULL); //conn 변수 초기화
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) { //Connect to database;
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(query, "SELECT name, point, rank() over (order by point desc) as ranking from ranking;"); //info 테이블에 있는 데이터를 모두 가져오는 query 작성
	mysql_query(conn, query);

	res = mysql_store_result(conn); //query 결과값 res 변수에 저장하기

	while ((row = mysql_fetch_row(res)) != NULL)  //NULL 값이 나올 때 까지 출력
	{
		printf("이름 = %s\t점수 = %s\t순위 = %s\n", row[0], row[1], row[2]); //형식에 맞게 출력
	}

	mysql_free_result(res); //결과값 비우기
	mysql_close(conn); //mysql 연결 해제
}