#define _CRT_SECURE_NO_WARNINGS
#define ESIG 0x06054B50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct I1 {
	int hour;
	int min;
	int sec;
} n;

struct I2 {
	int year;
	int month;
	int day;
} m;

struct I3 {
	int fsize;
	int lfile;
	int lfield;
	int lcmt;

} k;


int main(int argc, char* argv[]) {

	int i = 0, j = 0;
	short date = 0, num = 0, count = 0;
	int  offset = 0, vsize = 0, total = 0;
	int tm[20] = { 0, }, dt[20] = { 0, };
	char* ptr;
	FILE* fp;
	char buffer[50] = "";
	char str1[10] = "";
	char str2[10] = "";

	if (argc == 2) {
		fp = fopen("C:\\C.zip", "rb");
		printf("%s 안에 포함된 파일은 다음과 같습니다.\n", argv[1]);

		while (j != ESIG) {
			fseek(fp, -22 - i, SEEK_END);
			fread(&j, 1, 4, fp);
			i++;
		}

		fseek(fp, 6, SEEK_CUR);
		fread(&num, 1, 2, fp); // 내부 파일 개수
		fseek(fp, 4, SEEK_CUR);
		fread(&offset, 1, 4, fp);

		while (count < num) {
			fseek(fp, offset + 12 + 46 * count + vsize, SEEK_SET);// 날짜
			fread(&date, 1, 2, fp);

			memset(&n, 0, sizeof(struct I1));
			memset(&m, 0, sizeof(struct I2));

			ptr = (char*)&date;

			for (i = 0; i < 2; i++)
				for (j = 0; j < 8; j++) {
					if (*(ptr + 1 - i) & (0x80 >> j)) tm[i * 8 + j] = 1;
					else tm[i * 8 + j] = 0;
				}

			for (i = 0; i < 16; i++) {
				if (i < 5) {
					if (tm[i]) n.hour += 1 << (4 - i);
				}
				else if (i < 11) {
					if (tm[i]) n.min += 1 << (10 - i);
				}
				else
					if (tm[i]) n.sec += 1 << (15 - i);
			}

			fread(&date, 1, 2, fp);
			ptr = (char*)&date;
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 8; j++) {
					if (*(ptr + 1 - i) & (0x80 >> j)) dt[i * 8 + j] = 1;
					else dt[i * 8 + j] = 0;
				}
			}

			for (i = 0; i < 16; i++) {
				if (i < 7) {
					if (dt[i]) m.year += 1 << (6 - i);
				}
				else if (i < 11) {
					if (dt[i]) m.month += 1 << (10 - i);
				}
				else
					if (dt[i]) m.day += 1 << (15 - i);
			}

			fseek(fp, 8, SEEK_CUR); //크기
			fread(&k.fsize, 1, 4, fp);
			total = total + k.fsize;

			if (k.fsize < 1000) strcpy(str1, "Bytes");
			else if (k.fsize < 1000 * 1000) {
				k.fsize /= 1000;
				strcpy(str1, "Kbytes");
			}
			else {
				k.fsize /= 1000 * 1000;
				strcpy(str1, "Mbytes");
			}

			fread(&k.lfile, 1, 2, fp);
			fread(&k.lfield, 1, 2, fp);
			fread(&k.lcmt, 1, 2, fp);
			vsize = vsize + k.lfile + k.lfield + k.lcmt;

			fseek(fp, 12, SEEK_CUR);
			fread(buffer, sizeof(char), k.lfile, fp);
			buffer[k.lfile - 1] = NULL;
			printf("%d. %s	%d %s  %d/%02d/%02d %02d:%02d:%02d\n",
				count + 1, buffer, k.fsize, str1, m.year + 1980, m.month, m.day,
				n.hour, n.min, n.sec * 2);
			count++;
		}

		if (total < 1000) strcpy(str2, "B");
		else if (total < 1000 * 1000) {
			total /= 1000;
			strcpy(str2, "KB");
		}
		else {
			total /= 1000 * 1000;
			strcpy(str2, "MB");
		}

		printf("- 모두 %d 개의 파일 (%d %s)입니다.\n", count, total, str2);
	}

}