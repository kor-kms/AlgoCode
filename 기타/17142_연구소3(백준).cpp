#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int map[50][50];
int visit[50][50];
int vir[10];
int n, m, k;
int result = 1000000;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int,int>> q;
vector<pair<int,int>> v;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back(pair<int,int>(i,j));
			else if (map[i][j] == 0) k++;
		}
	}
}

void solve() {
	int time = 0;
	int kk = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int xx = x + dx[w];
			int yy = y + dy[w];
			if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
			if (visit[xx][yy] == -1 && map[xx][yy] != 1) {
				visit[xx][yy] = visit[x][y] + 1;
				if (map[xx][yy] == 0) {
					time = visit[xx][yy];
					kk++;
				}
				q.push(pair<int,int>(xx,yy));
			}
		}
	}
	if (kk == k && result > time) result = time;
}

void check() {
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < v.size(); i++) {
		if (vir[i] == 1) {
			q.push(pair<int,int>(v[i].first, v[i].second));
			visit[v[i].first][v[i].second] = 0;
		}
	}
}

void dfs(int nn, int x) {
	if (nn == m) {
		check();
		solve();
		return;
	}

	for (int i = x; i < v.size(); i++) {
		if (vir[i] == 0) {
			vir[i] = 1;
			dfs(nn + 1, i + 1);
			vir[i] = 0;
		}
	}
}



int main() {
	input();
	dfs(0, 0);
	if(result == 1000000) cout << -1 << endl;
	else cout << result << endl;
	return 0;
}