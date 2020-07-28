#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

queue<pair<int, int>> q;
int k, ans;
int ar[4][8];

void input()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
			scanf("%1d", &ar[i][j]);
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		q.push({ a,b });
	}
}

void cl(int w)
{
	int temp = ar[w][7];
	int cp[8] = { 0, };
	for (int i = 0; i < 8; i++)
		cp[i] = ar[w][i];
	for (int i = 1; i < 8; i++)
		ar[w][i] = cp[i - 1];
	ar[w][0] = temp;
}

void rcl(int w)
{
	int temp = ar[w][0];
	int cp[8] = { 0, };
	for (int i = 0; i < 8; i++)
		cp[i] = ar[w][i];
	for (int i = 0; i < 7; i++)
		ar[w][i] = ar[w][i + 1];
	ar[w][7] = temp;
}

void solve()
{
	while (!q.empty())
	{
		int x = q.front().first - 1;
		int y = q.front().second;
		q.pop();

		int ch[3] = { 0, };
		for (int i = 0; i < 3; i++)
		{
			if (ar[i][2] == ar[i + 1][6])
				ch[i]++;
		}

		//1½Ã°è
		if (y == 1)
			cl(x);

		else if (y == -1)
			rcl(x);

		int temp = y;
		for (int i = x; i < 3; i++)
		{
			if (ch[i] != 0) break;
			if (temp == 1)
			{
				rcl(i + 1);
				temp = -1;
			}
			else if (temp == -1)
			{
				cl(i + 1);
				temp = 1;
			}
		}

		temp = y;
		for (int i = x; i > 0; i--)
		{
			if (ch[i - 1] != 0) break;
			if (temp == 1)
			{
				rcl(i - 1);
				temp = -1;
			}
			else if (temp == -1)
			{
				cl(i - 1);
				temp = 1;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (ar[i][0] == 1)
			ans += pow(2, i);
	}
}

int main()
{
	input();
	solve();
	cout << ans << endl;
	return 0;
}