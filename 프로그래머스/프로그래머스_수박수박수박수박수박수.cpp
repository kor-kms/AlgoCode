#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
	// ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
	char* answer = (char*)malloc(sizeof(char)*(n * 3));
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) strcpy(answer + i * 3, "��");
		else strcpy(answer + i * 3, "��");
	}
	return answer;
}