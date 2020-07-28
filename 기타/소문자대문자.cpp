#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;

	cin >> a;

	for (int i = 0; i < a.size(); i++) {
		int q = a[i];
		if (q > 96 && q < 123) {
			q -= 32;
			char w = q;
			a[i] = w;
		}
	}

	cout << a;
	return 0;
}