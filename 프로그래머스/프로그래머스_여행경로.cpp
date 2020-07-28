#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
bool flag = false;
vector<pair<string,bool>> v[26][26][26];
vector<string> res;

void dfs(int a, int b, int c, int ct)
{
	if (ct == n)
	{
		flag = true;
		return;
	}

	for (int w = 0; w < v[a][b][c].size(); w++)
	{
		if (!v[a][b][c][w].second)
		{
			v[a][b][c][w].second = true;
			string s = v[a][b][c][w].first;
			int x = s[0] - 'A';
			int y = s[1] - 'A';
			int z = s[2] - 'A';
			res.push_back(s);
			dfs(x, y, z, ct + 1);
			if (flag)
				break;
			res.pop_back();
			v[a][b][c][w].second = false;
		}
		if (flag)
			break;
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	queue<pair<int, pair<int, int>>> q;
	n = tickets.size() + 1;

	for (int i = 0; i < tickets.size(); i++)
	{
		int a = tickets[i][0][0] - 'A';
		int b = tickets[i][0][1] - 'A';
		int c = tickets[i][0][2] - 'A';
		v[a][b][c].push_back({ tickets[i][1],false });
		q.push({ a,{b,c} });
	}

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		sort(v[a][b][c].begin(), v[a][b][c].end());
	}

	res.push_back("ICN");
	dfs(8, 2, 13, 1);

	answer = res;
	return answer;
}

int main()
{
	solution({ {"ICN"} });
}