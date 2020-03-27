#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct S {
	char* ptr;
	int len;
}n[10] ;

int main(int argc, char argv[]) {
	FILE* fp;
	char str[120] = "";
	char* temp;
	char* kw[34] = { "auto","break","case","char","const","continue",
		"default","do","double","else","enum","extern","float","for",
		"goto","if","inline","int","long","register","restrict","return",
		"short","signed","sizeof","static","struct","switch","typedef",
		"union","unsigned","void","volatile","while" };
	int i = 0, j = 0, k = 0;
	int count = 0, start = 0, num = 0;

	if (argc == 2) {
		fp = fopen("C:\\test.c", "rt");

		while (fgets(str, 100, fp) != NULL) {
			count = 0;

			for (i = 0; i < 34; i++) {
				temp = strstr(str, kw[i]);
				while ((temp != NULL) && ((str[temp - &str[0] - 1] == ' ') ||
					(str[temp - &str[0] + strlen(kw[i])] == ' ') ||
					(str[temp - &str[0] + strlen(kw[i])] == '\n'))) {
					n[count].ptr = strstr(temp, kw[i]);
					n[count].len = strlen(kw[i]);
					count++;
					temp += strlen(kw[i]);
					temp = strstr(temp, kw[i]);
				}
			}

			for (i = 0; i < count - 1; i++) {
				if (n[i].ptr > n[i + 1].ptr) {
					temp = n[i].ptr;
					n[i].ptr = n[i + 1].ptr;
					n[i + 1].ptr = temp;

					num = n[i].len;
					n[i].len = n[i + 1].len;
					n[i + 1].len = num;
				}
			}

			start = n[0].ptr - &str[0];

			if (count > 0) {
				for (i = 0; i < start; i++) printf("%c", str[i]);
				printf("(");
				for (j = 0; j < n[0].len; j++) printf("%c", str[start + j]);
				printf(")");
				start += n[0].len;
				for (i = 0; i < count - 1; i++) {
					for (j = 0; j < (int)(n[i + 1].ptr - n[i].ptr) - n[i].len; j++) printf("%c", str[start + j]);
					printf("(");
					start += j;
					for (k = 0; k < n[i + 1].len; k++) printf("%c", str[start + k]);
					printf(")");
					start += k;
				}
				for (i = start; i < strlen(str); i++) printf("%c", str[i]);
			}
			else printf("%s", str);
		}
		fclose(fp);
	}

}