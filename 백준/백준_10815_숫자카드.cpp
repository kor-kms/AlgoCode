#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n;
set<int> s;
vector<int> v;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		s.insert(a);
	}
}

void solve()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		if (s.find(num) != s.end())
			v.push_back(1);
		else
			v.push_back(0);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

int main()
{
	input();
	solve();
	return 0;
}