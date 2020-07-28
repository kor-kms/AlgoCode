#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, ans;
int ar[14][21];
bool vi[14];

void input()
{
	ans = 987654321;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ar[i][j];
		}
	}
}

bool che()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ar[j][i] == 0)
			{
				int ct = 0;
				for (int w = 0; w < k; w++)
				{
					if (ar[j][i] == ar[j + w][i])
						ct++;
				}
				if (ct < k)
					return false;
				else
					break;
			}
		}
	}
	return true;
}

void pro()
{

}

void sovle()
{
	if (che())
	{
		ans = 0;
		return;
	}
	for (int i = 0; i < 2; i++)
	{

	}
}

int main()
{
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		input();
		sovle();
		cout << "#" << k + 1 << " " << ans << endl;
	}
	return 0;
}