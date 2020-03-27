#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {

	int year, month;
	int days_plus = 0;
	int month_day = 31;
	int month_days = 0;
	int what_day;

	printf("yyyy mm?\n");
	scanf("%d %d", &year, &month);

	switch (month) {
	case 2:
		month_day -= 3;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		month_day -= 1;
		break;
	}

	if ((!(year % 4) && (year % 100)) || (!(year % 100) && !(year % 400)))
		month_days += 1; //������ �� +1��

	for (int i = 1; i < month; i++) {

		if (i % 2 != 0)	month_days += 31; //Ȧ���� ���� ��ü�� 31��
		else
			month_days += 30;

		if (i == 2) month_days -= 2; //2���� ��� 28��
	}

	if (month == 9 || month == 11) month_days += 1; //¦���鼭 31���� ��

	for (int j = 1900; j < year; j++) {
		if (j % 4 == 0) days_plus += 1;
		if (j % 100 == 0) days_plus -= 1;
		if (j % 400 == 0) days_plus += 1;
	} //���� �� �� �ݿ�
	
	what_day = ((year - 1900) + month_days + days_plus + 1) % 7;
	/* 1900�� 1�� 1�� �� -> ����� ���� ���� ���
	������ 0~6 -> �� ~ ���� �ش� (������ +1�� ����) */

	printf("\nSUN MON TUE WED TUR FRI SAT\n");
	for (int k = 0; k < what_day; k++)
		printf("    "); // ���� ������ ����

	for (int l = 1; l <= month_day; l++) {
		if (l > 9) printf(" %d ", l);
		else printf(" %d  ", l);
		//ĭ �� ����(�� �ڸ� ������ ���� �� ĭ ����)

		if ((l + what_day) % 7 == 0) printf("\n");
		// �� �� + ���� ����ġ -> 1���� 
	}

	printf("\n");
}