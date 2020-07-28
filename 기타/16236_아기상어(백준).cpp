#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct aaa {
	int x;
	int y;
	int d;
	int size;
	int num;
};
aaa a;
queue<aaa> q;
vector<aaa> v;

int n;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int ar[20][20];
int vi[20][20];
//int size = 2;
//int num;
int result;

bool cmp(aaa a, aaa b) {
	if (a.d <= b.d) {
		if (a.d == b.d) {
			if (a.x <= b.x) {
				if (a.x == b.x) {
					if (a.y < b.y) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		int size = q.front().size;
		int num = q.front().num;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int xx = x + dx[w];
			int yy = y + dy[w];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n && vi[xx][yy] == 0) {
				if (ar[xx][yy] == 0 || ar[xx][yy] == size) {
					vi[xx][yy] = 1;
					q.push({ xx,yy,d + 1,size,num });
				}
				else if (ar[xx][yy] < size) {
					vi[xx][yy] = 1;
					v.push_back({ xx,yy,d + 1,size,num + 1 });
				}
			}
		}

	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ar[i][j];
			if (ar[i][j] == 9) {
				ar[i][j] = 0;
				a = { i,j,0,2,0 };
			}
		}
	}

	while (true) {
		q.push(a);
		vi[a.x][a.y] = 1;
		bfs();

		if (v.size() == 0) break;

		sort(v.begin(), v.end(), cmp);

		if (v[0].size == v[0].num) {
			v[0].size++;
			v[0].num = 0;
		}

		ar[v[0].x][v[0].y] = 0;
		result = v[0].d;
		a = { v[0].x, v[0].y, v[0].d, v[0].size, v[0].num };
		//memset(vi, 0, sizeof(vi));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vi[i][j] = 0;
			}
		}
		v.clear();
	}

	cout << result << endl;
	return 0;
}