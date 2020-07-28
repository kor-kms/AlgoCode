#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int a[16];
int aa[16];

void ttt(int num, int nnum) {
	int p = 0;
	memset(a, 0, sizeof(a));
	memset(aa, 0, sizeof(aa));
	while (1)
	{
		if (num > 0) {
			a[p] = num % 2;
			num = num / 2;
		}
		if (nnum > 0) {
			aa[p] = nnum % 2;
			nnum = nnum / 2;
		}
		p++;
		if (num == 0 && nnum == 0) break;
	}
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < arr1.size(); i++) {
		ttt(arr1[i], arr2[i]);
		string s = "";
		cout << arr1[i] << " " << arr2[i] << endl;
		for (int j = n - 1; j >= 0; j--) {
			cout << a[j] << " " << aa[j] << " " << (a[j] || aa[j]) << endl;
			if ((a[j] || aa[j]) == 0) {
				s += " ";
			}

			else if ((a[j] || aa[j]) == 1) {
				s += "#";
			}
			cout << endl;
		}
		cout << s << endl;
		answer.push_back(s);
	}
	return answer;
}

int main() {
	/*vector<int> v1 = { 9,20,28,18,11 };
	vector<int> v2 = { 30,1,21,17,28 };
	int n = 5;*/
	/*vector<int> v1 = { 46,33,33,22,31,50 };
	vector<int> v2 = { 27,56,19,14,14,10 };
	int n = 6;*/
	vector<int> v1 = { 22,31,50 };
	vector<int> v2 = { 14,14,10 };
	int n = 6;
	solution(n, v1, v2);
	return 0;
}