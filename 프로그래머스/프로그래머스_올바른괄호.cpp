#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') cnt++;
		else if (s[i] == ')')
		{
			if (cnt <= 0) return false;
			cnt--;
		}
	}
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;
	if (cnt != 0) return false;
	return answer;
}

int main()
{
	solution("(()(");
}