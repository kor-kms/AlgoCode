#include <vector>
using namespace std;

bool vi[200001];

int solution(vector<int> nums)
{
	int answer = 0;
	int n = nums.size() / 2;
	vector<int> v;

	for (int i = 0; i < nums.size(); i++)
	{
		if (!vi[nums[i]])
		{
			vi[nums[i]] = true;
			v.push_back(nums[i]);
		}
	}

	if (n > v.size()) answer = v.size();
	else answer = n;

	return answer;
}

#include <set>
#include <vector>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	int n = nums.size() / 2;
	set<int> s;

	for (int i = 0; i < nums.size(); i++)
		//if (s.find(nums[i]) == s.end())
		s.insert(nums[i]);

	if (n > s.size()) answer = s.size();
	else answer = n;

	return answer;
}