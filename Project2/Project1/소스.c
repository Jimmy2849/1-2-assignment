#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void Del_line(int arr[][4], int row, int col);

int main(void) {

	char ladder[20][9];
	int i, j, k;
	int col, order, flag;
	int count = 1;
	int random = 0;
	int line[19][4];
	int arr[4];
	int prob = 0;
	int min_line;
	int max_line;
	int num_start[5] = { 0, };
	int num_result[5][5] = { 0, };

	srand(time(NULL));

	while (count <= 100) {
		for (i = 0; i < 20; i++)
			for (j = 0; j < 9; j++)
				ladder[i][j] = 0;

		for (i = 0; i < 19; i++)
			for (j = 0; j < 4; j++)
				line[i][j] = 0;



		printf("1 2 3 4 5\n");

		for (i = 0; i < 20; i++) {
			for (j = 0; j < 9; j += 2)
				ladder[i][j] = '|';
		}

		/* 열의 line 개수세는 조건 추가..*/

		for (i = 0; i < 4; i++) arr[i] = -1;


		order = 0;

		while (order <= 3) {
			random = rand() % 4;

			arr[order] = random;

			for (i = 0; i < order; i++) if (arr[order] == arr[i]) break;

			if (i == order) {
				order++;
				flag = 1;
			}

			// 순서 정하기
			if (flag) {

				col = random * 2 + 1;
				min_line = 0;
				max_line = 0;

				while (min_line <= 3) {

					for (i = 0; i < 19; i += 2) {

						if (i == 18) {
							if ((rand() % 2) && (line[i][random] == 0)) {
								ladder[i][col] = '_';
								line[i][random] = 1;
								Del_line(line, i, random);
								max_line++;
								break;
							}
							else break;
						}

						prob = rand() % 2;

						if (rand() % 2) {
							if (prob && line[i][random] == 0) {
								ladder[i][col] = '_';
								line[i][random] = 1;
								Del_line(line, i, random);
								max_line++;
								if (max_line == 7) break;
							}

							else if (!prob && line[i + 1][random] == 0) {
								ladder[i + 1][col] = '_';
								line[i + 1][random] = 1;
								Del_line(line, i + 1, random);
								max_line++;
								if (max_line == 7) break;
							}

						}


					}

					for (i = 0; i < 19; i++) {
						if (line[i][random] == 1) min_line++;
					}

				}

			}

			flag = 0;

		}

		for (i = 0; i < 5; i++)
			num_start[i] = i;

		for (i = 0; i < 5; i++)
			for (j = 0; j < 19; j++)
				for (k = 0; k < 4; k++) {

					if (line[j][k] == 1) {
						if (num_start[i] == k) num_start[i]++;
						else if ((num_start[i] - k) == 1) num_start[i]--;
					}

				}

		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				if (num_start[i] == j)	num_result[i][j]++;



		for (i = 0; i < 20; i++) {
			for (j = 0; j < 9; j++)
				printf("%c", ladder[i][j]);

			printf("\n");
		}

		printf("A B C D E\n\n");
		count++;

	}

	for (i = 0; i < 5; i++)
		printf("%d : A(%d) B(%d) C(%d) D(%d) E(%d)   : %d \n",
		(i + 1), num_result[i][0], num_result[i][1], num_result[i][2],
			num_result[i][3], num_result[i][4], (count - 1));



}

void Del_line(int arr[][4], int row, int col) {

	if (col == 0)
		arr[row][col + 1] = -1;
	else if (col == 3)
		arr[row][col - 1] = -1;
	else {
		arr[row][col - 1] = -1;
		arr[row][col + 1] = -1;
	}

	int n;

	for (n = 0; n < 17; n++) {

		if ((arr[n + 1][col] == 1) && (arr[n][col] == 1)) {

			if (n == 0) {
				arr[n + 2][col] = -1; break;
			}

			arr[n - 1][col] = -1;
			arr[n + 2][col] = -1;

		}
	}

	for (n = 0; n < 17; n++) {
		if ((arr[n + 2][col] == 1) && (arr[n][col] == 1))
			arr[n + 1][col] = -1;
	}
}
