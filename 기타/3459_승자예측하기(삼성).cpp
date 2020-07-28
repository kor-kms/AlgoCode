#include <stdio.h>

int main(void) {
	int t;
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		unsigned long long n;
		unsigned long long x = 1;
		unsigned long long xx = 1;
		int flag = 0;

		scanf("%llu", &n);
		while (xx < n) {
			if (!flag) x *= 4;
			xx += x;
			flag = !flag;
		}
		printf("#%d %s\n", k + 1, flag ? "Alice" : "Bob");
	}

	return 0;
}