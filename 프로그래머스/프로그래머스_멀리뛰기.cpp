#include <string>
#include <vector>

using namespace std;

vector<int> v;

long long fac(int a, int b, int c)
{
	long long ans = 1;
	for (int i = a; i > b; i--)
		ans *= i;
	long long res = 1;
	for (int i = c; i > 0; i--)
		res *= i;
	return ans / res;
}

long long solution(int n) {
	long long answer = 1;
	for (int i = 0; i < n; i++)
		v.push_back(1);

	int cnt = 0;
	while (true)
	{
		if (v.size() < 2)
			break;
		v.pop_back();
		v.pop_back();
		cnt++;
		int all = v.size() + cnt;
		int mi = all - cnt;
		if (all == cnt)
			answer++;
		else if (cnt < mi)
			answer += fac(all, mi, cnt);
		else if (cnt >= mi)
			answer += fac(all, cnt, mi);
	}

	answer %= 1234567;
	return answer;
}

int main()
{
	solution(3);
}