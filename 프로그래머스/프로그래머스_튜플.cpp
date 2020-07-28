#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int vi[100001];

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if (a.first > b.first) return true;
	else return false;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<int> v;
	for (int i = 2; i < s.size(); i++)
	{
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			string num;
			num += s[i];
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[j] - '0' >= 0 && s[j] - '0' <= 9)
				{
					num += s[j];
				}
				else
				{
					i = j - 1;
					break;
				}
			}
			v.push_back(stoi(num));
		}
	}

	for (int i = 0; i < v.size(); i++) vi[v[i]]++;
	
	vector<pair<int, int>> ans;

	for (int i = 0; i < 100001; i++)
	{
		if (vi[i] != 0)
		{
			ans.push_back({ vi[i],i });
		}
	}

	sort(ans.begin(), ans.end(), cmp);

	for (int i = 0; i < ans.size(); i++)
	{
		answer.push_back(ans[i].second);
	}
	return answer;
}

int main()
{
	solution("{{20,111},{111}}");
}