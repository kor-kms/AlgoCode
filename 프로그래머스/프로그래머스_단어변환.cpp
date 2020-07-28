#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	queue<pair<string, int>> q;
	bool vi[50] = { false, };
	q.push(make_pair(begin, 0));
	while (!q.empty())
	{
		string s = q.front().first;
		int x = q.front().second;
		q.pop();

		if (s == target)
		{
			answer = x;
			break;
		}

		for (int w = 0; w < words.size(); w++)
		{
			if (!vi[w])
			{
				bool flag = false;
				int ct = 0, temp = 0;
				for (int i = 0; i < words[w].size(); i++)
				{
					if (ct > 1)
						break;
					if (s[i] != words[w][i])
					{
						temp = i;
						flag = true;
						ct++;
					}
				}
				if (flag && ct == 1)
				{
					vi[w] = true;
					q.push({ words[w],x + 1 });
				}
			}
		}
	}

	return answer;
}

int main()
{
	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}