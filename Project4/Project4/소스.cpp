#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
int len_result(char arr[], int count);

int main(void) {
	int i, j, num;
	char x[42] = "";
	char y[42] = "";
	char big[42] = "";
	char small[42] = "";
	int len_x, len_y;
	int len_big = 0;
	int len_sml = 0;
	int neg_x = 0;
	int neg_y = 0;
	int neg_big = 0;
	int neg_sml = 0;
	int size = 0;
	char plus[43] = "";
	char minus[43] = "";
	char mult[82] = "";

	printf("input X : ");
	scanf("%s",x);

	printf("input Y : ");
	scanf("%s",y);

	len_x = strlen(x);
	len_y = strlen(y);

	if (x[0] == '-') {
		x[0] = '0';
		len_x--;
		neg_x = 1;
	}

	if (y[0] == '-') {
		y[0] = '0';
		len_y--;
		neg_y = 1;
	}

	//'-'가 -48로 인해 NULL값이 되므로 strcpy에서 아무것도 복사되지 않음
	if (len_x > len_y) {
		strcpy(big, x);
		strcpy(small, y);
		len_big = len_x;
		len_sml = len_y;
	}
	else if (len_x < len_y) {
		strcpy(big, y);
		strcpy(small, x);
		size = 1;
		len_big = len_y;
		len_sml = len_x;
	}
	else {
		for (i = 0; i < len_x; i++) {
			if (x[i + neg_x] > y[i + neg_y]) {
				strcpy(big, x);
				strcpy(small, y);
				len_big = len_x;
				len_sml = len_y;
				break;
			}
			else if (y[i + neg_y] > x[i + neg_x]) {
				strcpy(big, y);
				strcpy(small, x);
				size = 1;
				len_big = len_y;
				len_sml = len_x;
				break;
			}
		}
		if (i == len_x) {
			strcpy(big, x);
			strcpy(small, y);
			len_big = len_x;
			len_sml = len_y;
		}
	}

	if (big[0] == '0') neg_big = 1;
	if (small[0] == '0') neg_sml = 1;
		
	for (i = 0; i < len_big + neg_big; i++)
		big[i] = big[i] - 48;

	for (i = 0; i < len_sml + neg_sml; i++)
		small[i] = small[i] - 48;

	//곱셈
	for (i = 0; i < len_sml; i++) {
		for (j = 0; j < len_big; j++) {
			num = big[len_big + neg_big - j - 1] * small[len_sml + neg_sml - i - 1];
			mult[i + j + 1] = mult[i + j + 1] + ((num - (num % 10)) / 10);
			mult[i + j] = mult[i + j] + num % 10;
			if (mult[i + j] >= 10) {
				mult[i + j] -= 10;
				mult[i + j + 1]++;
			}
		}
	}

	if (neg_big + neg_sml == 1) mult[len_result(mult, 82)] = '-';

	//양수 양수 or 음수 음수일 때(0 0 / 1 1)
	if (neg_x == neg_y) {

		for (i = 0; i < len_sml; i++) {
			plus[i] = plus[i] + big[len_big + neg_big - i - 1] + small[len_sml + neg_sml - i - 1];
			if (plus[i] >= 10) {
				plus[i] -= 10;
				plus[i + 1]++;
			}
		}
		if (len_big > len_sml) {
			for (i = len_sml; i < len_big; i++) {
				plus[i] = plus[i] + big[len_big + neg_big - i - 1];
				if (plus[i] >= 10) {
					plus[i] -= 10;
					plus[i + 1]++;
				}
			}
		}
		if (neg_x) plus[len_result(plus, 43)] = '-';

		for (i = 0; i < len_sml; i++) {
			minus[i] = minus[i] + big[len_big + neg_big - i - 1] - small[len_sml + neg_sml - i - 1];
			if (minus[i] < 0) {
				minus[i] += 10;
				minus[i + 1]--;
			}
		}
		if (len_big > len_sml) {
			for (i = len_sml; i < len_big; i++) {
				minus[i] = minus[i] + big[len_big + neg_big - i - 1];
				if (minus[i] < 0) {
					minus[i] += 10;
					minus[i + 1]--;
					}
				}
			}
			if ((!neg_x && size) || (neg_x && !size)) minus[len_result(minus, 43)] = '-';
			//양수일 때 y가 큰 경우, 음수일 때 x가 큰 경우
		}

	//양수 음수 or 음수 양수 일 때(0 1 / 1 0)
	else {
		for (i = 0; i < len_sml; i++) {
			minus[i] = minus[i] + big[len_big + neg_big - i - 1] + small[len_sml + neg_sml - i - 1];
			if (minus[i] >= 10) {
				minus[i] -= 10;
				minus[i + 1]++;
			}
		}
		if (len_big > len_sml) {
			for (i = len_sml; i < len_big; i++) {
				minus[i] = minus[i] + big[len_big + neg_big - i - 1];
				if (minus[i] >= 10) {
					minus[i] -= 10;
					minus[i + 1]++;
				}
			}
		}
		if (neg_x) minus[len_result(minus,43)] = '-';

		for (i = 0; i < len_sml; i++) {
			plus[i] = plus[i] + big[len_big + neg_big - i - 1] - small[len_sml + neg_sml - i - 1];
			if (plus[i] < 0) {
				plus[i] += 10;
				plus[i + 1]--;
			}
		}
		if (len_big > len_sml) {
			for (i = len_sml; i < len_big; i++) {
				plus[i] = plus[i] + big[len_big + neg_big - i - 1];
				if (plus[i] < 0) {
					plus[i] += 10;
					plus[i + 1]--;
				}
			}
		}
			if ((neg_x && !size) || (!neg_x && size)) plus[len_result(plus, 43)] = '-';
			//음수 x의 절댓값이 큰 경우, 음수 y의 절댓값이 큰 경우 
		}

	printf("X + Y : ");
	if (plus[len_result(plus, 43) - 1] != '\0') printf("%c", plus[len_result(plus,43)]);
	for (i = 0; i < len_result(plus,43); i++) 
		printf("%d", plus[len_result(plus,43) - i - 1]);
		printf("\n");

	printf("X - Y : ");
	if (plus[len_result(minus, 43) - 1] != '\0') printf("%c", minus[len_result(minus,43)]);
	for (i = 0; i < len_result(minus,43); i++)
		printf("%d", minus[len_result(minus,43) - i - 1]);
	printf("\n");

	printf("X * Y :");
	printf("%c", mult[len_result(mult,82)]);
	for (i = 0; i < len_result(mult,82); i++)
		printf("%d", mult[len_result(mult,82) - i - 1]);
	printf("\n");

}

int len_result(char arr[], int count) {
	int i;
	int value = 1;

	for (i = 0; i < count; i++)
		if ((arr[i] > 0) && (arr[i] != '-')) value = i + 1;

	return value;

}

	
			









