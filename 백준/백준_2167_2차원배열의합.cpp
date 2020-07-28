#include <iostream>

using namespace std;

int main()
{
	int ar[300][300] = { 0, };
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ar[i][j];
		}
	}
	cin >> k;
	for (int t = 0; t < k; t++)
	{
		int a, b, x, y, res = 0;
		cin >> a >> b >> x >> y;
		a--;
		b--;
		x--;
		y--;
		for (int i = a; i < n; i++)
		{
			for (int j = b; j < m; j++)
			{
				res += ar[i][j];
				if (j == y)
					break;
			}
			if (i == x)
				break;
		}
		cout << res << endl;
	}
	return 0;
}