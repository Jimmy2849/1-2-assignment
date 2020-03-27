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
		{"시작",}, {"서울",},{"도쿄",},{"시드니",},{"LA",},
	{"카이로",},{ "푸켓",},{ "뉴 델리",},{ "하노이",},{"파리",}
	};

	struct PLAYER p[2] = {
		{5000,}, {5000,}
	};

	int turn = 0, dice = 0;
	int n;

	printf("우리의 마블을 시작합니다.\n");
	printboard(c, p);
	srand((unsigned int)time(NULL));

	while (turn < 30) {
		n = 0;

		printf("TURN : %d\n", turn + 1);

		while (n < 2) {

			dice =  (rand()% 6) + 1;
			printf("\nPLAYER%d의 차례 : %d\n", n + 1, dice);
				p[n].location = p[n].location + dice;
			if (p[n].location > 9) p[n].location -= 10;
			if (!p[n].location) printf("PLAYER%d가 시작 타일에 도착\n\n", n + 1);
			else {
				switch (c[p[n].location].state) {
				case 0:
					if (p[n].money >= 300) {
						p[n].money -= 300;
						c[p[n].location].state = n + 1;
						printf("PLAYER%d가 %s 타일을 구매\n", n + 1, c[p[n].location].name);
						printf("PLAYER%d의 돈 : %d\n\n", n + 1, p[n].money);
					}
					else if (p[n].money < 300) {
						printf("구매불가\n");
						printf("PLAYER%d의 돈 : %d\n\n", n + 1, p[n].money);
					}
					break;

				case 1:
					if (n) {
						p[1].money -= 600;
						p[0].money += 600;
						printf("PLAYER2가 %s 타일에 도착\n", c[p[n].location].name);
						printf("PLAYER2의 돈 : %d\n", p[1].money);
						printf("PLAYER1의 돈 : %d\n\n", p[0].money);
					}
					else printf("PLAYER1가 %s 타일에 도착\n\n", c[p[n].location].name);
					break;

				case 2:
					if (!n) {
						p[0].money -= 600;
						p[1].money += 600;
						printf("PLAYER1가 %s 타일에 도착\n", c[p[n].location].name);
						printf("PLAYER1의 돈 : %d\n", p[0].money);
						printf("PLAYER2의 돈 : %d\n\n", p[1].money);
					}
					else printf("PLAYER2가 %s 타일에 도착\n\n", c[p[n].location].name);
					break;
				}
			}

			printboard(c, p);

			if (p[n].money < 0) {
				printf("PLAYER%d이 파산하였습니다. PLAYER%d의 승리!\n", n+1, 2-n);
				printf("PLAYER1의 돈 : %d\n", p[0].money);
				printf("PLAYER2의 돈 : %d\n", p[1].money);
				return;
			}
			n++;
		}
		turn++;

	}

	printf("모든 턴이 끝났습니다.\n");
	printf("PLAYER1의 돈 : %d\n", p[0].money);
	printf("PLAYER2의 돈 : %d\n", p[1].money);
	if (p[0].money > p[1].money) printf("PLAYER1의 승리!\n");
	else if (p[1].money > p[0].money) printf("PLAYER2의 승리!\n");
	else printf("무승부!\n");
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
	printf("\n  ↑\t\t\t\t\t\t      ↓\n");				 
	for (i = 4; i>=1 ; i--) {							
		printf("%s(%d)", (cptr + i)->name, (cptr + i)->state);
		for (j = 0; j < 10 - strlen((cptr + i)->name); j++) printf(" ");
	}
	printf("시작\n");
	for (i = 4; i>=0 ; i--)  {
	if (((pptr->location) == i) && (((pptr + 1)->location) == i)) printf("[1][2]       ");
	else if ((pptr->location) == i) printf("[1][]        ");
	else if (((pptr + 1)->location) == i) printf("[][2]        ");
	else
	printf("[][]         ");
	}
	printf("\n\n");

}
	



