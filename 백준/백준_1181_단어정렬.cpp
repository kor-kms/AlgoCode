#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct cmp
{
	bool operator()(const string a, const string b) const
	{
		if (a.size() < b.size())
			return true;
		else if (a.size() == b.size())
		{
			if (a < b)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

set<string, cmp> s;
set<string>::iterator iter;
int n;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string c;
		cin >> c;
		iter = s.find(c);
		if (iter == s.end())
			s.insert(c);
	}
}

int main()
{
	input();
	for (auto i : s)
		cout << i << endl;
	return 0;
}