#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void) {
	char word[2][9] = { "","" };
	const char *end = "end";
	int i, j;
	int num1, num2;
	int flag;

		do {
			printf("Word? ");
			scanf("%s", word[0]);
		} while ((strlen(word[0]) < 3) || (strlen(word[0]) > 8));
		

		while (1) {
			if (!strcmp(end, word[0])) break;
			num1 = -1;
			num2 = -1;
			flag = 0;

		do {
			printf("Word? ");
			scanf("%s", word[1]);
		} while ((strlen(word[1]) < 3) || (strlen(word[1]) > 8));
		if (!strcmp(end, word[1])) break;

		for (i = 0; i < strlen(word[0]); i++) {
			for (j = 0; j < strlen(word[1]); j++) {
				if (word[0][i] == word[1][j]) {
					num1 = i;
					num2 = j;
					flag = 1;
					break;
					}
				
				}
			if (flag) break;
		}

				if (num1 == -1) printf("no cross word\n");
				else {
					for (i = 0; i < num1; i++) printf("%c", word[0][i]);
					printf("(");
					printf("%c", word[0][num1]);
					printf(")");
					for (i = num1 + 1; i < strlen(word[0]); i++) printf("%c", word[0][i]);
					printf(" - ");

					for (i = 0; i < num2; i++) printf("%c", word[1][i]);
					printf("(");
					printf("%c", word[1][num2]);
					printf(")");
					for (i = num2 + 1; i < strlen(word[1]); i++) printf("%c", word[1][i]);
					printf("\n");
				}

				for (i = 0; i < strlen(word[1]); i++) word[0][i] = '\0';
				strcpy(word[0], word[1]);
				for (i = 0; i < strlen(word[1]); i++) word[1][i] = '\0';
			}
	} 

