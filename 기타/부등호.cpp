#include <iostream>

using namespace std;

int a, b, t;
char q;
int main() {
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> a >> b;
		if (a > b) q = '>';
		else if (a < b) q = '<';
		else if (a == b) q = '=';
		cout << "#" << k + 1 << " " << q << endl;
	}
	return 0;
}