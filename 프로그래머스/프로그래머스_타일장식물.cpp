#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long answer = 0;
	long long dp[80] = { 1,1,2,3,5, };
	long long ar[80] = { 4,6,10,16,26, };
	for (int i = 5; i < 80; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	
	for (int i = 5; i < 80; i++)
		ar[i] = ar[i - 1] + dp[i] * 2;

	answer = ar[N - 1];

	return answer;
}

int main()
{
	solution(5);
}