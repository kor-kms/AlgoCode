#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int map[101][101];
int n, k, l, time;
struct aaa {
	int c;
	char d;
};
aaa ch[100];
struct vvv {
	int xa;
	int ya;
	int sa;
};
vector<vvv> v;
list<pair<int, int>> q;

void input() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> ch[i].c >> ch[i].d;
	}
}

void solve() {
	int t = 0;
	int st = 0;
	q.push_back({ 1,1 });

	while (true) {
		int x = q.back().first;
		int y = q.back().second;

		if (time == ch[t].c) {//0 오른쪽 1 아래 2 왼쪽 3 위
			if (st == 0) {
				if (ch[t].d == 'D') {
					st = 1;
				}
				else {
					st = 3;
				}
			}
			else if (st == 1) {
				if (ch[t].d == 'D') {
					st = 2;
				}
				else {
					st = 0;
				}
			}
			else if (st == 2) {
				if (ch[t].d == 'D') {
					st = 3;
				}
				else {
					st = 1;
				}
			}
			else if (st == 3) {
				if (ch[t].d == 'D') {
					st = 0;
				}
				else {
					st = 2;
				}
			}
			t++;
		}

		if (st == 0) {//0 오른쪽 1 아래 2 왼쪽 3 위
			y += 1;
			bool eat = false;
			int si = q.size();
			for (int i = 0; i < si; i++) {
				int xx = q.front().first;
				int yy = q.front().second;
				q.pop_front();
				if (x == xx && y == yy) {
					eat = true;
					break;
				}
				q.push_back({ xx,yy });
			}
			if (eat) break;
			if (y > n) break;
			else {
				bool hh = false;
				for (int i = 0; i < k; i++) {
					if (x == v[i].xa && y == v[i].ya && v[i].sa == 0) {
						v[i].sa = 1;
						q.push_back({ x,y });
						hh = true;
						break;
					}
				}
				if (hh == false) {
					q.pop_front();
					q.push_back({ x,y });
				}
			}
		}
		else if (st == 1) {
			x += 1;
			bool eat = false;
			int si = q.size();
			for (int i = 0; i < si; i++) {
				int xx = q.front().first;
				int yy = q.front().second;
				q.pop_front();
				if (x == xx && y == yy) {
					eat = true;
					break;
				}
				q.push_back({ xx,yy });
			}
			if (eat) break;
			if (x > n) break;
			else {
				bool hh = false;
				for (int i = 0; i < k; i++) {
					if (x == v[i].xa && y == v[i].ya && v[i].sa == 0) {
						v[i].sa = 1;
						q.push_back({ x,y });
						hh = true;
						break;
					}
				}
				if (hh == false) {
					q.pop_front();
					q.push_back({ x,y });
				}
			}
		}
		else if (st == 2) {
			y -= 1;
			bool eat = false;
			int si = q.size();
			for (int i = 0; i < si; i++) {
				int xx = q.front().first;
				int yy = q.front().second;
				q.pop_front();
				if (x == xx && y == yy) {
					eat = true;
					break;
				}
				q.push_back({ xx,yy });
			}
			if (eat) break;
			if (y < 1) break;
			else {
				bool hh = false;
				for (int i = 0; i < k; i++) {
					if (x == v[i].xa && y == v[i].ya && v[i].sa == 0) {
						v[i].sa = 1;
						q.push_back({ x,y });
						hh = true;
						break;
					}
				}
				if (hh == false) {
					q.pop_front();
					q.push_back({ x,y });
				}
			}
		}
		else if (st == 3) {
			x -= 1;
			bool eat = false;
			int si = q.size();
			for (int i = 0; i < si; i++) {
				int xx = q.front().first;
				int yy = q.front().second;
				q.pop_front();
				if (x == xx && y == yy) {
					eat = true;
					break;
				}
				q.push_back({ xx,yy });
			}
			if (eat) break;
			if (x < 1) break;
			else {
				bool hh = false;
				for (int i = 0; i < k; i++) {
					if (x == v[i].xa && y == v[i].ya && v[i].sa == 0) {
						v[i].sa = 1;
						q.push_back({ x,y });
						hh = true;
						break;
					}
				}
				if (hh == false) {
					q.pop_front();
					q.push_back({ x,y });
				}
			}
		}
		time++;
	}
}

int main() {
	input();
	solve();
	cout << time + 1 << endl;
	return 0;
}