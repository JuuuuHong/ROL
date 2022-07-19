#include "header.h"

MYSQL* conn; //mysql���� Ŀ�ؼ��� ��µ� ���������� ���Ǵ� ����
MYSQL_RES* res; //�������� ���� result ���� �޴� ����
MYSQL_ROW row; //�������� ���� ���� ������ ���� ���� ����

char* server = "localhost"; //MySQL ������ ��� -- localhost = ���� ��ǻ��
char* user = "root"; //MySQL �α��� ���̵�, Default value = root
char* password = "158pk158."; //MySQL �α��� �� �� ���̴� password ��
char* database = "rankdb"; //Database �̸��� ����

void insert(char name[15], int point){
	char query[255]; //SQL Query ���� ����

	conn = mysql_init(NULL); //conn ���� �ʱ�ȭ
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) { //Connect to database;
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(query, "insert into ranking values('%s',%d);", name, point); //query ������ insert SQL�� ����
	mysql_query(conn, query); //query ������

	mysql_close(conn); //���� ����
}

void view() {
	char query[255]; //SQL Query ���� ����

	conn = mysql_init(NULL); //conn ���� �ʱ�ȭ
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) { //Connect to database;
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(query, "SELECT name, point, rank() over (order by point desc) as ranking from ranking;"); //info ���̺� �ִ� �����͸� ��� �������� query �ۼ�
	mysql_query(conn, query);

	res = mysql_store_result(conn); //query ����� res ������ �����ϱ�

	while ((row = mysql_fetch_row(res)) != NULL)  //NULL ���� ���� �� ���� ���
	{
		printf("�̸� = %s\t���� = %s\t���� = %s\n", row[0], row[1], row[2]); //���Ŀ� �°� ���
	}

	mysql_free_result(res); //����� ����
	mysql_close(conn); //mysql ���� ����
}