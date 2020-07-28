#include <iostream>

using namespace std;

int a;

int main() {
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> a;
		int ct = 0;
		for (int i = 1; i <= a; i++) {
			if(i%2 == 1) ct += i;
			else ct -= i;
		}
		cout << "#" << k + 1 << " " << ct << endl;
	}
	return 0;
}