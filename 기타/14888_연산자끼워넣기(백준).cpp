#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[11];
int ca[4];
int remax = -1000000001, remin = 1000000001;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> ca[i];
	}
}

void solve(int count, int re, int cc) {
	ca[cc]--;

	switch (cc)
	{
	case 0:
		re += map[count];
		break;
	case 1:
		re -= map[count];
		break;
	case 2:
		re *= map[count];
		break;
	case 3:
		re /= map[count];
		break;
	default:
		break;
	}

	if (count == n - 1) {
		remax = max(remax, re);
		remin = min(remin, re);
	}

	else {
		for (int i = 0; i < 4; i++) {
			if (ca[i] > 0) {	
				solve(count + 1, re, i);
			}
		}
	}
	ca[cc]++;
}

int main() {
	input();
	for (int i = 0; i < 4; i++) {
		if (ca[i] > 0) {
			solve(1, map[0], i);
		}
	}
	cout << remax << endl << remin << endl;
	return 0;
}