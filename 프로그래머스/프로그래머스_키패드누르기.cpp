#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> ar[10] = { {3,1}, {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2} };

string solution(vector<int> numbers, string hand) {
	string answer = "";
	pair<int, int> lh = { 3, 0 }, rh = { 3, 2 };
	bool flag = false;
	if (hand == "right")
		flag = true;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer += 'L';
			lh = ar[numbers[i]];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer += 'R';
			rh = ar[numbers[i]];
		}
		else
		{
			int dl = abs(ar[numbers[i]].first - lh.first) + abs(ar[numbers[i]].second - lh.second);
			int dr = abs(ar[numbers[i]].first - rh.first) + abs(ar[numbers[i]].second - rh.second);
			if (dl > dr)
			{
				answer += 'R';
				rh = ar[numbers[i]];
			}
			else if (dl < dr)
			{
				answer += 'L';
				lh = ar[numbers[i]];
			}
			else if (dl == dr)
			{
				if (flag)
				{
					answer += 'R';
					rh = ar[numbers[i]];
				}
				else
				{
					answer += 'L';
					lh = ar[numbers[i]];
				}
			}
		}
	}

	return answer;
}