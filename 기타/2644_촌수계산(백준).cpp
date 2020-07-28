#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> v[100];
int visit[100];
int n, m, d1, d2;
int result;
bool qq = false;

void input() {
	cin >> n >> d1 >> d2 >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		visit[i] = 1;
	}
}

void bfs() {
	q.push(d1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == d2) {
			result = visit[x] - 1;
			qq = true;
			break;
		}

		for (int i = 0; i < v[x].size(); i++) {
			if (visit[v[x][i]] == 1) {
				visit[v[x][i]] += visit[x];
				q.push(v[x][i]);
			}
		}
	}
}

int main() {
	input();
	bfs();
	if(qq) cout << result << endl;
	else cout << -1 << endl;
	return 0;
}