#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> r;
set<int> point;
vector<int> s;
bool vi[20001];
int n;

void pro(int i)
{
	if (s.size() == n)
	{

		return;
	}

	for (int w = i; w < n * 2; w++)
	{
		if (!vi[w])
		{
			vi[w] = true;
			set<int>::iterator iter = point.begin();
			for (int ct = 0; ct < w; ct++)
				iter++;

			int cnt = 0;
			int cam = *iter;
			for (int j = 0; j < n; j++)
			{
				if (cam >= r[j][0] && cam <= r[j][1])
				{
					s.push_back(j);
					cnt++;
				}
			}

			pro(w);

			for (int j = 0; j < cnt; j++)
				s.pop_back();
			vi[w] = false;
		}
	}
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	n = routes.size();
	r = routes;

	for (int i = 0; i < routes.size(); i++)
	{
		point.insert(routes[i][0]);
		point.insert(routes[i][1]);
	}

	pro(0);

	return answer;
}

int main()
{
	solution({{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}});
}