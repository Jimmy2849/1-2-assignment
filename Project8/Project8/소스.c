#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#pragma comment(lib,"winmm") 
#include <Windows.h>

int main()
{
	int i = 1;
	int key[4] = { 0, };
	FILE * fp;
	printf("Sound play\n");
	PlaySoundA("C:\\¸®µë\\»ç³ªÀÌ.wav", NULL, SND_ASYNC);
	fp = fopen("C:\\¸®µë\\½Î³ªÀÌ.dat", "wb");

	while (1) {

		fprintf(fp, "%05d\t", i);

		if (GetAsyncKeyState(VK_LEFT)) {
			printf(" *\t");
			key[0] = 1;
			fprintf(fp, "%d", key[0]);
		}
		else {
			printf(" \t");
			key[0] = 0;
			fprintf(fp, "%d", key[0]);
		}

		if (GetAsyncKeyState(VK_UP)) {
			printf("*\t");
			key[1] = 1;
			fprintf(fp, "%d", key[1]);
		}
		else {
			printf("\t");
			key[1] = 0;
			fprintf(fp, "%d", key[1]);
		}

		if (GetAsyncKeyState(VK_DOWN)) {
			printf("*\t");
			key[2] = 1;
			fprintf(fp, "%d", key[2]);
		}
		else {
			printf("\t");
			key[2] = 0;
			fprintf(fp, "%d", key[2]);
		}

		if (GetAsyncKeyState(VK_RIGHT)) {
			printf("*\t");
			key[3] = 1;
			fprintf(fp, "%d", key[3]);
		}
		else {
			printf("\t");
			key[3] = 0;
			fprintf(fp, "%d", key[3]);
		}

		if (GetAsyncKeyState(VK_RETURN)) {
			PlaySoundA(NULL, 0, 0);
			break;
		}
		printf("\n");
		fprintf(fp, "\n");
		i++;
		Sleep(50);//0.05 ÃÊ
	}
}