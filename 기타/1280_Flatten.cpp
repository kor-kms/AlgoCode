#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	/*int t[2] = { 0,0 };
	for(int i=0;i<2;i++) scanf("%1d", &t[i]);
	int w = t[0] * 10 + t[1];*/

	for (int k = 0; k < 10; k++) {
		int n[5] = { 0, };
		if (k == 4) {
			for (int i = 0; i<4; i++) scanf("%1d", &n[i]);
			int q = n[0] * 10 + n[1];

			int ar[100] = { 0, };
			ar[0] = n[2] * 10 + n[3];

			for (int i = 1; i < 100; i++) scanf("%d", &ar[i]);
			for (int i = q; i >= 0; i--) { //while 시간초과 for는 시간초과 x 이유는 불명
				sort(ar, ar + 100);
				ar[99]--;
				ar[0]++;
			}

			printf("#%d %d\n", k + 1, ar[99] - ar[0] + 2);
		}


		else {
			for (int i = 0; i < 5; i++) scanf("%1d", &n[i]);
			int q = n[0] * 100 + n[1] * 10 + n[2];

			int ar[100] = { 0, };
			ar[0] = n[3] * 10 + n[4];

			for (int i = 1; i < 100; i++) scanf("%d", &ar[i]);
			for (int i = q; i >= 0; i--) { //while 시간초과 for는 시간초과 x 이유는 불명
				sort(ar, ar + 100);
				ar[99]--;
				ar[0]++;
			}

			printf("#%d %d\n", k + 1, ar[99] - ar[0] + 2);
		}
	}
	return 0;
}