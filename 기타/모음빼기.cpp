#include <iostream>
#include <string>

using namespace std;

string a;
char ar[50];
int t;

int main() {
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> a;
		int q = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') continue;
			else {
				ar[q] = a[i];
				q++;
			}
		}
		cout << "#" << k + 1 << " ";
		for (int i = 0; i < q; i++) {
			cout << ar[i];
		}
		cout << endl;
	}
	return 0;
}