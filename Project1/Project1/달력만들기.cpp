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
		month_days += 1; //윤년일 때 +1일

	for (int i = 1; i < month; i++) {

		if (i % 2 != 0)	month_days += 31; //홀수인 달은 대체로 31일
		else
			month_days += 30;

		if (i == 2) month_days -= 2; //2월은 평년 28일
	}

	if (month == 9 || month == 11) month_days += 1; //짝수면서 31일인 달

	for (int j = 1900; j < year; j++) {
		if (j % 4 == 0) days_plus += 1;
		if (j % 100 == 0) days_plus -= 1;
		if (j % 400 == 0) days_plus += 1;
	} //윤년 일 수 반영
	
	what_day = ((year - 1900) + month_days + days_plus + 1) % 7;
	/* 1900년 1월 1일 월 -> 경과일 수로 요일 계산
	나머지 0~6 -> 일 ~ 월에 해당 (마지막 +1로 인해) */

	printf("\nSUN MON TUE WED TUR FRI SAT\n");
	for (int k = 0; k < what_day; k++)
		printf("    "); // 요일 시작점 설정

	for (int l = 1; l <= month_day; l++) {
		if (l > 9) printf(" %d ", l);
		else printf(" %d  ", l);
		//칸 수 조정(두 자리 수부터 공백 한 칸 줄임)

		if ((l + what_day) % 7 == 0) printf("\n");
		// 일 수 + 요일 가중치 -> 1주일 
	}

	printf("\n");
}