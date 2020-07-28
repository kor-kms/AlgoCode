#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;
	char ar[20];
	int n = name.size();

	for (int i = 0; i < n; i++) {
		ar[i] = name[i];
		if (ar[i] != 'A') {
			int a = ar[i] - 'A';
			if (a > 13) answer += 26 - a;
			else answer += a;
			if (i == 0 && ar[i] != 'A') ar[i] = 'A';
		}
	}
	
	int now = 0;//현재위치 변수
	while (true) {
		bool flag = false;
		int r = 0;//오른쪽으로 몇번인가 변수
		int l = 0;//왼쪽으로 몇번인가 변수
		//오른쪽 검사
		int ct1 = 0;
		
		for (int i = 1; i < n; i++) {
			r++;
			ct1++;
			if (now + ct1 == n) ct1 = -now;
			if (ar[now + ct1] == 'A') continue;
			else {
				flag = true;
				break;
			}
		}
		if (!flag) break;

		//왼쪽 검사
		int ct2 = 0;
		for (int i = 1; i < n; i++) {
			l++;
			ct2++;
			if (now - ct2 == -1) ct2 = now - n + 1;
			if (ar[now - ct2] == 'A') continue;
			else break;
		}

		if (r <= l) {
			answer += r;
			ar[now + ct1] = 'A';
			now = now + ct1;
		}
		else {
			answer += l;
			ar[now - ct2] = 'A';
			now = now - ct2;
		}

	}

	return answer;
}

int main() {
	solution("JEROEN");
}