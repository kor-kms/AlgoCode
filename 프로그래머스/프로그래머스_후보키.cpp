#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int cnt, n, ans, m;
int vi[21];

vector<vector<string>> s;
vector<vector<int>> res;

bool che()
{
	vector<string> v;
	for (int j = 0; j < n; j++)
		v.push_back("");

	for (int i = 0; i < m; i++)
	{
		if (vi[i] == 1)
		{
			for (int j = 0; j < n; j++)
				v[j] += s[j][i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] == v[j])
				return false;
		}
	}
	return true;
}

void pro(int ct, int i)
{
	if (ct == cnt)
	{
		bool flag = false;
		for (int w = 0; w < res.size(); w++)
		{
			int che_ct = 0;
			for (int q = 0; q < res[w].size(); q++)
			{
				if (vi[res[w][q]] == 1)
					che_ct++;
			}
			if (che_ct == res[w].size())
			{
				flag = true;
				break;
			}
		}

		if (!flag && che())
		{
			ans++;
			vector<int> vv;
			for (int w = 0; w < m; w++)
			{
				if (vi[w] == 1)
					vv.push_back(w);
			}
			res.push_back(vv);
		}

		return;
	}

	for (int w = i; w < m; w++)
	{
		if (vi[w] == 0)
		{
			vi[w] = 1;
			pro(ct + 1, w);
			vi[w] = 0;
		}
	}
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	n = relation.size();
	m = relation[0].size();
	s = relation;

	for (int i = 1; i <= m; i++)
	{
		cnt = i;
		pro(0, 0);
	}

	answer = ans;
	return answer;
}

int main()
{
	//solution({ {"a","1","4"}, {"2","1","5"},{"a","2","4"} });
	//solution({ {"a","b","c"}, {"1","b","c"},{"a","b","4"},{"a","5","c"} });
	//solution({ {"1","a","b","1","2"},{"2","a","a","1","1"},{"3","b","b","1","2"},{"4","b","a","2","1"} });
	solution({ {"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"} });
}