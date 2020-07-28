#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n, m, ans;
bool vi[26];
char ar[21][21];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool flag = false;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s", &ar[i]);
	}
}

void pro(int i, int j, int ct) {
	ans = max(ans, ct);

	for (int w = 0; w < 4; w++) {
		int nx = i + dx[w];
		int ny = j + dy[w];
		int a = ar[i][j] - 'A';
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (!vi[a]) {
			vi[a] = true;
			pro(nx, ny, ct + 1);
			vi[a] = false;
		}
	}
}

int main() {
	input();
	pro(0, 0, 0);
	cout << ans << endl;
	return 0;
}