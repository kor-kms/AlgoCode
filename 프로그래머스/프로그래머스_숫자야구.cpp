#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	for (int i = 123; i <= 987; i++)
	{
		string s = to_string(i);
		if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) continue;
		if (s[0] == '0' || s[1] == '0' || s[2] == '0') continue;

		bool flag = true;
		for (int j = 0; j < baseball.size(); j++)
		{
			int strike = 0; int ball = 0;
			string num = to_string(baseball[j][0]);
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (a == b && s[a] == num[b])
					{
						strike++;
						break;
					}
					else if (s[a] == num[b])
					{
						ball++;
						continue;
					}
				}
			}

			if (strike != baseball[j][1] || ball != baseball[j][2])
			{
				flag = false;
				break;
			}
		}
		if (flag) answer++;
	}

	return answer;
}