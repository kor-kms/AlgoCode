#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<string, int> DtoB(int n)
{
	pair <string, int> s;
	int R;
	while (true)
	{
		if (n == 1) break;
		R = n % 2;
		if (R == 1)
		{
			s.second++;
			n = (n / 2);
		}
		else if (R == 0) n = n / 2;
		s.first += to_string(R);
	}

	s.first += '1';
	return s;
}

int solution(int n) {
	int answer = 0;
	pair <string, int> s = DtoB(n);
	string S;
	for (int i = n + 1;; i++)
	{
		pair <string, int> q = DtoB(i);
		if (s.second == q.second) {
			S = q.first;
			break;
		}
	}

	for (int i = 0; i < S.size(); i++)
	{
		if(S[i] == '1') answer += pow(2, i);
	}
	return answer;
}

int main()
{
	solution(78);
}