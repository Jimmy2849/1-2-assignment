#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#pragma comment(lib,"winmm") 
#include <Windows.h>
#include <stdlib.h>

int main()
{	
	
	FILE* fp;
	int score = 0, miss = 0;
	int i = 0, j = 0, start = 0;
	int input[4] = { 0, };
	char str[24][20] = { "", };

	fp = fopen("C:\\리듬\\사나이.dat", "rb");

	while (fgets(str[j], 15, fp) != NULL) {

		if (start == 24) {
			PlaySoundA("C:\\리듬\\사나이.wav", NULL, SND_ASYNC);
		}

		if (j == 23) {
			if ((str[0][6] - 48) && (GetAsyncKeyState(VK_LEFT))) {
				score += 100;
				miss = 0;
			}
			else if ((!(str[0][6] - 48) != !(GetAsyncKeyState(VK_LEFT)))) {
				if (miss > 2) score -= 150;
				else miss++;
			}

			if ((str[0][7] - 48) && (GetAsyncKeyState(VK_UP) )) {
				score += 100;
				miss = 0;
			}
			else if ((!(str[0][7] - 48) != !(GetAsyncKeyState(VK_UP)))) {
				if (miss > 2) score -= 150;
				else miss++;
			}

			if ((str[0][8] - 48) && (GetAsyncKeyState(VK_DOWN))) {
				score += 100;
				miss = 0;
			}
			else if ((!(str[0][8] - 48) != !(GetAsyncKeyState(VK_DOWN)))) {
				if (miss > 2) score -= 150;
				else miss++;
			}

			if ((str[0][9] - 48) && (GetAsyncKeyState(VK_RIGHT))) {
				score += 100;
				miss = 0;
			}
			else if ((!(str[0][9] - 48) != !(GetAsyncKeyState(VK_RIGHT)))) {
				if (miss > 2) score -= 150;
				else miss++;
			}
		}

		fseek(fp, -5, SEEK_CUR);
		for (i = 0; i < 4; i++) fread(input + i, 1, 1, fp);
		fseek(fp, 1, SEEK_CUR);

		for (i = 0; i < 4; i++) {
			if (atoi(input + i)) printf(" *\t");
			else if (!atoi(input + i)) printf(" \t");
		}
		 
		if (start >= 24) printf("\t\t현재 점수 : %d", score);

		printf("\n");
		start++;
		if (j < 23) j++;
		else if (j == 23) for (i = 0; i < 23; i++) strcpy(str[i], str[i + 1]);
		Sleep(50);
	}
}