#include <string>
#include <vector>

using namespace std;

int Fi(int num)
{
	if (num == 1) return 1;
	else if (num == 2) return 1;
	else return Fi(num - 1) + Fi(num - 2);
}

int solution(int n) {
	int answer;
	answer = Fi(n) % 123456789;
	return answer;
}

int main()
{
	solution(5);
}