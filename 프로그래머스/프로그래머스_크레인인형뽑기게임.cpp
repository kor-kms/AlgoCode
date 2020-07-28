#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int n = board.size();

	vector<int> v[30];
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (board[j][i] == 0)
				continue;
			v[i].push_back(board[j][i]);
		}
	}

	vector<int> res;
	for (int i = 0; i < moves.size(); i++)
	{
		int temp = moves[i] - 1;
		if (v[temp].empty())
			continue;
		int doll = v[temp].back();
		v[temp].pop_back();
		if (res.empty())
			res.push_back(doll);
		else
		{
			if (res.back() == doll)
			{
				res.pop_back();
				answer += 2;
			}
			else
				res.push_back(doll);
		}
	}

	return answer;
}