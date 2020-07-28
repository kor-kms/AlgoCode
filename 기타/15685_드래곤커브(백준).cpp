#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
struct aaa {
	int x;
	int y;
	int d;
	int g;
};
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
aaa ar[20];
vector<pair<int, int>> v[20];
int map[100][100];
int ans;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].y >> ar[i].x >> ar[i].d >> ar[i].g;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		v[i].push_back({ ar[i].x,ar[i].y });
		v[i].push_back({ ar[i].x + dx[ar[i].d], ar[i].y + dy[ar[i].d] });
		for (int j = 0; j < ar[i].g; j++) {
			int lx = v[i].back().first;
			int ly = v[i].back().second;
			v[i].pop_back();
			vector<pair<int, int>> vv;
			queue<pair<int, int>> qq;
			while (!v[i].empty()) {
				int xx = v[i].back().first;
				int yy = v[i].back().second;
				v[i].pop_back();
				int nx = 0;
				int ny = 0;
				int fx = xx - lx;
				int fy = yy - ly;
				if ((xx > lx && yy > ly) || (xx < lx && yy < ly)) {
					nx = fx;
					ny = -fy;
				}
				else if ((xx > lx && yy < ly) || (xx < lx && yy > ly)) {
					nx = -fx;
					ny = fy;
				}
				else {
					if (xx == lx) {
						nx = fy;
						ny = fx;
					}
					else if (yy == ly) {
						nx = -fy;
						ny = -fx;
					}
				}
				nx += lx;
				ny += ly;
				vv.push_back({ xx,yy });
				qq.push({ nx,ny });
			}
			while (!vv.empty()) {
				v[i].push_back({ vv.back().first,vv.back().second });
				vv.pop_back();
			}
			v[i].push_back({ lx, ly });
			while (!qq.empty()) {
				v[i].push_back({ qq.front().first,qq.front().second });
				qq.pop();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			map[v[i][j].first][v[i][j].second] = 1;
		}
	}
	for (int i = 0; i < 99; i++) {
		for (int j = 0; j < 99; j++) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) ans++;
		}
	}
}

int main() {
	input();
	solve();
	cout << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << map[j][i] << " ";
		}cout << endl;
	}
	cout << ans << endl;
	return 0;
}