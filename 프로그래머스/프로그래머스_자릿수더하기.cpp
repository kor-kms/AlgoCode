#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
	int answer = 0;
	string s = to_string(n);
	for (int i = 0; i < s.size(); i++) {
		int a = s[i] - '0';
		answer += a;
	}
	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "Hello Cpp" << endl;

	return answer;
}