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
	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "Hello Cpp" << endl;
	if (cnt != 0) return false;
	return answer;
}

int main()
{
	solution("(()(");
}