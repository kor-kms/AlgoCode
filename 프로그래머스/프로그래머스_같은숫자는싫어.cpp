#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int c = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (i == 0) answer.push_back(arr[i]);
		if (answer[c] == arr[i]) continue;
		else {
			c++;
			answer.push_back(arr[i]);
		}
	}
	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "Hello Cpp" << endl;

	return answer;
}