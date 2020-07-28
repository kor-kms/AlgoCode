#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;

	set<string> s;
	set<string>::iterator iter;
	s.insert(words[0]);
	
	for (int i = 1; i < words.size(); i++)
	{
		if (words[i - 1][words[i - 1].size() - 1] != words[i][0])
		{
			int b = 0;
			b = i % n;
			b++;
			answer.push_back(b);
			int a = 0;
			a = i / n + 1;
			answer.push_back(a);
			break;
		}

		iter = s.find(words[i]);
		if (iter == s.end())
		{
			s.insert(words[i]);
		}
		else
		{
			int b = 0;
			b = i % n;
			b++;
			answer.push_back(b);
			int a = 0;
			a = i / n + 1;
			answer.push_back(a);
			break;
		}
	}

	if (answer.size() == 0)
	{
		answer.push_back(0);
		answer.push_back(0);
	}

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
	cout << "Hello Cpp" << endl;

	return answer;
}

int main()
{
	//solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });
	solution(2, { "hello", "one", "even", "never", "now", "world", "draw" });
}