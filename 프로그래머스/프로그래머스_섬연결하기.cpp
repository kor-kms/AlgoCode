#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	if (a.first < b.first)
		return true;
	else
		return false;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < costs.size(); i++)
		v.push_back({ costs[i][2],{costs[i][0],costs[i][1]} });

	sort(v.begin(), v.end(), cmp);
	return answer;
}

int main()
{
	solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}});
}