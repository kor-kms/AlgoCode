#include <iostream>

using namespace std;

int n;
int m;
int c;
int h;
int k;
int a;
int b;
int aa[100000];

int main() {

	cin >> n >> m;
	int** ar = new int*[n];
	for (int i = 0; i < n; ++i) {
		ar[i] = new int[n];
		memset(ar[i], 0, sizeof(int) * n);
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		ar[a][b] = 1;
	}
	cin >> c >> h >> k;
	c--;
	h--;
	ar[c][c] = 5;
	ar[h][h] = 3;

	for (int i = 0; i < n; i++) {
		if (ar[h][i] == 1) {
			aa[i] = -1;
		}
	}

	int q = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ar[i][j] == 1 && aa[j] != -1) {
				aa[j] = q;
			}
		}
		q++;
	}













	for (int i = 0; i < n; i++) {
		if (ar[h][i] == 1) {
			ar[i][0] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (ar[i][0] != -1) {
			for (int j = 0; j < n; j++) {
				if (ar[i][j] == 1) {
					
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}



	for (int i = 0; i < n; i++) {
		delete[] ar[i];
	}
	delete[] ar;

	return 0;
}