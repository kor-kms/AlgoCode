#include <iostream>
#include <algorithm>

using namespace std;

int t, n;
int ar[50];

int main() {
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar + n);
		cout << "#" << k + 1 << " ";
		for (int i = 0; i < n; i++) {
			cout << ar[i] << " ";
		}
		cout << endl;
	}
	return 0;
}