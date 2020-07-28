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
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}