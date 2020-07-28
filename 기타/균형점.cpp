#include <iostream>

using namespace std;

int nn;
struct nnnn {
	int x;
	int m;
};
nnnn n[10];

int main() {
	cout << fixed;
	cout.precision(10);
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> nn;
		for (int i = 0; i < nn; i++) {
			cin >> n[i].x;
		}
		for (int i = 0; i < nn; i++) {
			cin >> n[i].m;
		}

		
		cout << "#" << k + 1 << " ";
		double an = 0;
		while (an == 0) {

		}

	}
	return 0;
}