#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f(int (*arr)[3], int row) {
	
	int i, j;

	for (i = 0; i < row ; i++)
		for (j = 0; j < 3; j++)
			arr[i][j] = 1;

	for (i = 0; i < row; i++)
		for (j = 0; j < 3; j++)
			printf("%d ", arr[i][j]);

	printf("\n");

}


int main(void) {

	int line[4][3] = {0, };
	int i, j;

	f(line, sizeof(line) / sizeof(line[0]));

	for (i = 0; i < sizeof(line) / sizeof(line[0]); i++)
		for (j = 0; j < 3; j++)
			printf("%d ", line[i][j]);
	printf("\n");
	
	}