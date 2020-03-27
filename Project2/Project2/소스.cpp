
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {

	char ladder[20][9] = { 0, };

	int i, j;
	int count = 0;
	int random;

	srand(time(NULL));

		printf("1 2 3 4 5\n");

		for (i = 0; i < 20; i++) {
			for (j = 0; j < 9; j += 2)
				ladder[i][j] = "|";
			for (j = 1; j < 9; j += 2) {
				random = (rand() % 4) * 2 + 1;
				if (random == j) ladder[i][j] = "_";
			}
		}
		for (i = 0; i < 20; i++) {
			for (j = 0; j < 9; j++)
				printf("%c", ladder[i][j]);

			printf("\n");
		}
}






}