#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		else
			return a.second > b.second;
	}
};


int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int s = 0, t = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	for (int i = 0; i < jobs.size(); i++)
		q.push({ jobs[i][0],jobs[i][1] });

	while (!q.empty())
	{
		pair<int, int> a = { q.top().first, q.top().second };
		q.pop();
		if (a.first <= s)
		{
			s += a.second;
			t += s - a.first;
		}
		else
		{
			pq.push(a);
			bool flag = false;	
			while (!q.empty())
			{
				pair<int, int> b = { q.top().first, q.top().second };
				q.pop();
				if (b.first <= s)
				{
					s += b.second;
					t += s - b.first;
					flag = true;
					break;
				}
				else
					pq.push(b);
			}
			if (!flag)
				s++;
			while (!pq.empty())
			{
				q.push(pq.top());
				pq.pop();
			}
		}
	}

	answer = t / jobs.size();
	return answer;
}

int main()
{
	//solution({ {0, 3 }, { 1, 9 }, { 2, 6 } });
	//solution({{0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}});
	//solution({{1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3}});
	solution({{0, 3}, {4, 4}, {5, 3}, {4, 1}});
	solution({{0, 3}, {1, 9}, {500, 6}});
	solution({{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}