#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* fp;
	char buffer[100] = "";
	char str[30] = "";
	char temp[100] = "";
	char letter = '\0';
	char* ptr = "";
	char** sp = NULL;
	int start = 0;
	int score = 0, exist = 0;
	int i = 0, n = 1;
	int round = 0, count = 0;
	int cword = 0, size = 0;
	int flag = 0;

	srand(time(NULL));

	sp = malloc(sizeof(char*) * 100 * n);
	fp = fopen("C:\\dict_test.txt", "rt");

	while (1) {
		size = 0;
		exist = 0;

		if (!str[0]) {
			while (fgets(buffer, 90, fp) != NULL) size++;
			fseek(fp, 0, SEEK_SET);
		}
		else {
			memset(buffer, 0, 100);
			fseek(fp, 0, SEEK_SET);
			while (tolower(buffer[0]) != letter) fgets(buffer, 90, fp);
			fseek(fp, -(signed int)strlen(buffer) - 1, SEEK_CUR);
			start = ftell(fp);
			while ((tolower(buffer[0]) == letter) && (fgets(buffer, 90, fp) != NULL)) size++;
			size--;
			fseek(fp, start, SEEK_SET);
		}

		if (count == 99) {
			n++;
			sp = realloc(sp, sizeof(char*) * 100 * n);
		}

		do  {
			flag = 0;
			i = 0;
			if (count >=2) fseek(fp, start, SEEK_SET);
			else fseek(fp, 0, SEEK_SET);
			cword = ((rand() << 15) | rand()) % size; 
			while (i <= cword) { //cword + 1 ��° �ܾ�
				fgets(buffer, 90, fp);
				i++;
			}
			strcpy(temp, buffer);
			ptr = strtok(temp, ":");
			ptr[strlen(ptr) - 1] = NULL; // temp ������ NULL ��.
			for (i = 0; i < count; i++) {
				if (!strcmp(*(sp + i), ptr)) flag = 1;
			}
		} while ((strlen(ptr) < 4) || (strlen(ptr) > 10) || flag);

			count++;
			*(sp + count - 1) = malloc(strlen(ptr) + 1);
			strcpy(*(sp + count - 1), ptr);
			letter = ptr[strlen(ptr) - 1];
			if (letter == '.') letter = ptr[strlen(ptr) - 2];
			buffer[strlen(buffer) - 1] = NULL;
		
		printf("��ǻ���� �����Դϴ�.\n");
		printf("%s\n", buffer);
		printf("������� �����Դϴ�.\n");

		while (!exist) {
			printf("�ܾ �Է��ϼ���\n");
			gets(str);
			while (strlen(str) < 4 || strlen(str) > 10) {
				printf("�ܾ� ���̰� ���� �ʽ��ϴ�.\n");
				round++;
				if (round == 3) {
					printf("�й��߽��ϴ�.\n");
					return 0;
				}
				printf("�ܾ �Է��ϼ���\n");
				gets(str);


				while (str[0] != letter) {
					printf("Ʋ�Ƚ��ϴ�.\n");
					round++;
					if (round == 3) {
						printf("�й��߽��ϴ�.\n");
						return 0;
					}
					printf("�ܾ �Է��ϼ���\n");
					gets(str);
				}

				while (i < count) {
					for (i = 0; i < count; i++)
						if (!strcmp(*(sp + i), str)) {
							printf("������ �Է��� �ܾ��Դϴ�.\n");
							round++;
							if (round == 3) {
								printf("�й��߽��ϴ�.\n");
								return 0;
							}
							printf("�ܾ �Է��ϼ���\n");
							gets(str);
							break;
						}
				}
			}

			fseek(fp, 0, SEEK_SET);
			while (fgets(buffer, 90, fp) != NULL) {
				strcpy(temp, buffer);
				ptr = strtok(temp, ":");
				ptr[strlen(ptr) - 1] = NULL;
				if (!strcmp(str, ptr)) {
					count++;
					*(sp + count - 1) = malloc(strlen(str) + 1);
					strcpy(*(sp + count - 1), str);
					letter = str[strlen(str) - 1];
					buffer[strlen(buffer) - 1] = NULL;
					printf("%s\n", buffer);
					score = score + strlen(str);
					printf("�¾ҽ��ϴ�.(���� %d)\n", score);
					
					exist = 1;
					break;
				}
			}

			if (fgets(temp, 90, fp) == NULL) { 
				fseek(fp, 0, SEEK_SET);
				printf("������ �������� �ʴ� �ܾ��Դϴ�.\n");
				round++;
				if (round == 3) {
					printf("�й��߽��ϴ�.\n");
					return 0;
				}
			}

		}


	}
}

