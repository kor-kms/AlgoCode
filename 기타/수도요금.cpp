#include <iostream>

using namespace std;

int t, p, q, r, s, w;
int a, b;
int main() {
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> p >> q >> r >> s >> w;
		a = p*w;
		if(r > w) b = q;
		else b = q + s*(w - r);
		
		if (a > b) cout << "#" << k + 1 << " " << b << endl;
		else cout << "#" << k + 1 << " " << a << endl;
	}
	return 0;
}