#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* fp;
	char str[100] = "Hello\n";

	if (str[5] == '\n') printf("¾ß!\n");
	else printf("È£!\n");
}
	