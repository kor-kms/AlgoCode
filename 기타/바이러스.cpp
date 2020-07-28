#include <iostream>

using namespace std;

int n;
int m;


int main() {
	cin >> n >> m;

	int** ar = new int*[n];
	for (int i = 0; i < n; ++i) {
		ar[i] = new int[n];
		memset(ar[i], 0, sizeof(int) * n);
	}
	
	int a = 0;
	int b = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ar[a][b] = 1;
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