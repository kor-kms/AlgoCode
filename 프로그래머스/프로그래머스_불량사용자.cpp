#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> user, banned;
bool vi[8];
vector<int> ans;
set<string> s_id;

void pro(int ct)
{
	if (ct == banned.size())
	{
		vector<int> res = ans;
		sort(res.begin(), res.end());
		string s = "";
		for (auto i : res)
			s += to_string(i);
		s_id.insert(s);
		return;
	}

	for (int i = 0; i < user.size(); i++)
	{
		string s = banned[ct];
		if (s.size() != user[i].size())
			continue;

		if (!vi[i])
		{
			bool flag = false;
			for (int j = 0; j < user[i].size(); j++)
			{
				if (s[j] == '*')
					continue;
				if (s[j] != user[i][j])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				vi[i] = true;
				ans.push_back(i);
				pro(ct + 1);
				ans.pop_back();
				vi[i] = false;
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	user = user_id;
	banned = banned_id;

	pro(0);

	answer = s_id.size();
	return answer;
}