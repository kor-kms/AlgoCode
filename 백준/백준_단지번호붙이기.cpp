#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int ar[26][26];
int vi[26][26];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;
vector<int> v;
vector<int> ans;
int ct = 0; int ct2 = 0;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%1d", &ar[i][j]);
	}
}

void bfs(int i, int j) {
	ct = 0;
	ct2++;
	queue<pair<int, int>> q;
	q.push({ i,j });
	vi[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		ct++;

		for (int w = 0; w < 4; w++) {
			int nx = x + dx[w];
			int ny = y + dy[w];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (ar[nx][ny] != 0 && vi[nx][ny] == 0) {
				vi[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}

	v.push_back(ct);
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ar[i][j] != 0 && vi[i][j] == 0) bfs(i, j);
		}
	}
	ans.push_back(ct2);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) ans.push_back(v[i]);
}

int main() {
	input();
	solve();
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	return 0;
}