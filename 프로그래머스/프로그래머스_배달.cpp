#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<pair<int, int>> v[60];
bool vi[60];
int k;
int res = 0;
set<int> s;
set<int>::iterator iter;

void dfs(int a, int ctk)
{
	for (auto i : v[a])
	{
		if (!vi[i.first])
		{
			vi[i.first] = true;
			if (ctk + i.second <= k)
			{
				iter = s.find(i.first);
				if (iter == s.end())
					s.insert(i.first);
				dfs(i.first, ctk + i.second);
			}
			vi[i.first] = false;
		}
	}
}

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	k = K;
	for (int i = 0; i < road.size(); i++)
	{
		v[road[i][0]].push_back({ road[i][1],road[i][2] });
		v[road[i][1]].push_back({ road[i][0],road[i][2] });
	}

	s.insert(1);
	vi[1] = true;
	dfs(1, 0);
	answer = s.size();
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}

int main()
{
	//solution(5, {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}}, 3);
	solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4);
	//solution(6, { {1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 1}, {5, 6, 1} }, 4);

}