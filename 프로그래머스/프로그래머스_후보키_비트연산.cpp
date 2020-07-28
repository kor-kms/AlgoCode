#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans, m;

bool che(vector<vector<string>> v, int n, int m, int c)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			bool flag = false;
			for (int w = 0; w < m; w++)
			{
				if ((c & (1 << w)) == 0)
					continue;
				if (v[i][w] != v[j][w])
				{
					flag = true;
					break;
				}
			}

			if (!flag)
				return false;
		}
	}
	return true;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	n = relation.size();
	m = relation[0].size();
	vector<int> v;

	for (int i = 1; i < (1 << m); i++)
	{
		if (che(relation, n, m, i))
			v.push_back(i);
	}

	return answer;
}

int main()
{
	//solution({ {"a","1","4"}, {"2","1","5"},{"a","2","4"} });
	//solution({ {"a","b","c"}, {"1","b","c"},{"a","b","4"},{"a","5","c"} });
	//solution({ {"1","a","b","1","2"},{"2","a","a","1","1"},{"3","b","b","1","2"},{"4","b","a","2","1"} });
	solution({ {"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"} });
}