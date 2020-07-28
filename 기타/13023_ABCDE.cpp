#include <iostream>
#include <vector>

using namespace std;

vector<int> v[2000];
int vi[2000];
int ct;
bool q = false;
int n, m;

void dfs(int a, int x) {
	if (a == 5)
	{
		q = true;
		return;
	}

	vi[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		if (vi[v[x][i]] == 0) {
			dfs(a + 1, v[x][i]);
		}
		if (q) break;
	}
	vi[x] = 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		dfs(1, i);
		if (q) break;
	}

	if (q) cout << "1" << endl;
	else cout << "0" << endl;

	return 0;
}