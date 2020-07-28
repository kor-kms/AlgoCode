#include <stdio.h>
#include <algorithm>

char data[501];
char arr[501], arr2[501];
int calc[501];
int a, b, c;
char d[4][2] = { { 0, 3 },{ -1, -1 },{ 2, 2 },{ 1, 1 } };
int main() {
	int tc, N, i;
	for (tc = 1; tc <= 10; tc++)
	{
		scanf("%d", &N); scanf("%s", data);
		a = b = c = 0;
		for (i = 0; i < N; i++) {
			if (data[i] == '(' || data[i] == '+' || data[i] == '*') {
				while (b > 0 && d[arr2[b - 1] - '('][0] >= d[data[i] - '('][1]) {
					arr[a] = arr2[b - 1];
					a++;
					b--;
				}
				arr2[b] = data[i];
				b++;
			}
			else if (data[i] == ')')
			{
				while (arr2[b - 1] != '(') {
					arr[a] = arr2[b - 1];
					a++;
					b--;
				}
				b--;
			}
			else if (data[i] >= '0' && data[i] <= '9')
			{
				arr[a] = data[i];
				a++;
			}
		}
		while (b) {
			arr[a] = arr2[b - 1];
			a++;
			b--;
		}

		for (i = 0; i < a; i++) {
			if (arr[i] >= '0' && arr[i] <= '9') {
				calc[c] = arr[i] - '0';
				c++;
			}
			else if (arr[i] == '+') {
				calc[c - 2] = calc[c - 2] + calc[c - 1];
				c--;
			}
			else if (arr[i] == '*') {
				calc[c - 2] = calc[c - 2] * calc[c - 1];
				c--;
			}
		}
		printf("#%d %d\n", tc, calc[0]);
	}
	return 0;

}