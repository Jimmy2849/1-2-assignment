#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct CITY {
	char name[12];
	int state;
};

struct PLAYER {
	int money;
	int location;
};

void printboard(struct CITY* cptr, struct PLAYER* pptr);

int main()
{
	struct CITY c[10] = {
		{"����",}, {"����",},{"����",},{"�õ��",},{"LA",},
	{"ī�̷�",},{ "Ǫ��",},{ "�� ����",},{ "�ϳ���",},{"�ĸ�",}
	};

	struct PLAYER p[2] = {
		{5000,}, {5000,}
	};

	int turn = 0, dice = 0;
	int n;

	printf("�츮�� ������ �����մϴ�.\n");
	printboard(c, p);
	srand((unsigned int)time(NULL));

	while (turn < 30) {
		n = 0;

		printf("TURN : %d\n", turn + 1);

		while (n < 2) {

			dice =  (rand()% 6) + 1;
			printf("\nPLAYER%d�� ���� : %d\n", n + 1, dice);
				p[n].location = p[n].location + dice;
			if (p[n].location > 9) p[n].location -= 10;
			if (!p[n].location) printf("PLAYER%d�� ���� Ÿ�Ͽ� ����\n\n", n + 1);
			else {
				switch (c[p[n].location].state) {
				case 0:
					if (p[n].money >= 300) {
						p[n].money -= 300;
						c[p[n].location].state = n + 1;
						printf("PLAYER%d�� %s Ÿ���� ����\n", n + 1, c[p[n].location].name);
						printf("PLAYER%d�� �� : %d\n\n", n + 1, p[n].money);
					}
					else if (p[n].money < 300) {
						printf("���źҰ�\n");
						printf("PLAYER%d�� �� : %d\n\n", n + 1, p[n].money);
					}
					break;

				case 1:
					if (n) {
						p[1].money -= 600;
						p[0].money += 600;
						printf("PLAYER2�� %s Ÿ�Ͽ� ����\n", c[p[n].location].name);
						printf("PLAYER2�� �� : %d\n", p[1].money);
						printf("PLAYER1�� �� : %d\n\n", p[0].money);
					}
					else printf("PLAYER1�� %s Ÿ�Ͽ� ����\n\n", c[p[n].location].name);
					break;

				case 2:
					if (!n) {
						p[0].money -= 600;
						p[1].money += 600;
						printf("PLAYER1�� %s Ÿ�Ͽ� ����\n", c[p[n].location].name);
						printf("PLAYER1�� �� : %d\n", p[0].money);
						printf("PLAYER2�� �� : %d\n\n", p[1].money);
					}
					else printf("PLAYER2�� %s Ÿ�Ͽ� ����\n\n", c[p[n].location].name);
					break;
				}
			}

			printboard(c, p);

			if (p[n].money < 0) {
				printf("PLAYER%d�� �Ļ��Ͽ����ϴ�. PLAYER%d�� �¸�!\n", n+1, 2-n);
				printf("PLAYER1�� �� : %d\n", p[0].money);
				printf("PLAYER2�� �� : %d\n", p[1].money);
				return;
			}
			n++;
		}
		turn++;

	}

	printf("��� ���� �������ϴ�.\n");
	printf("PLAYER1�� �� : %d\n", p[0].money);
	printf("PLAYER2�� �� : %d\n", p[1].money);
	if (p[0].money > p[1].money) printf("PLAYER1�� �¸�!\n");
	else if (p[1].money > p[0].money) printf("PLAYER2�� �¸�!\n");
	else printf("���º�!\n");
}

void printboard(struct CITY *cptr, struct PLAYER *pptr) {
	 
	int i, j;
		for (i = 5; i < 10; i++) {
		printf("%s(%d)", (cptr + i)->name, (cptr + i)->state);
		for (j = 0; j < 10 - strlen((cptr + i)->name); j++) printf(" ");
	}
	printf("\n");
	for (i = 5; i < 10; i++) {
	if (((pptr->location) == i) && (((pptr+1)->location) == i)) printf("[1][2]       ");
	else if ((pptr->location) == i) printf("[1][]        ");
	else if (((pptr+1)->location) == i) printf("[][2]        ");
	else
	printf("[][]         ");
	}
	printf("\n  ��\t\t\t\t\t\t      ��\n");				 
	for (i = 4; i>=1 ; i--) {							
		printf("%s(%d)", (cptr + i)->name, (cptr + i)->state);
		for (j = 0; j < 10 - strlen((cptr + i)->name); j++) printf(" ");
	}
	printf("����\n");
	for (i = 4; i>=0 ; i--)  {
	if (((pptr->location) == i) && (((pptr + 1)->location) == i)) printf("[1][2]       ");
	else if ((pptr->location) == i) printf("[1][]        ");
	else if (((pptr + 1)->location) == i) printf("[][2]        ");
	else
	printf("[][]         ");
	}
	printf("\n\n");

}
	



