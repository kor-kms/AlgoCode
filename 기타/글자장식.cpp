#include <iostream>
#include <string>

using namespace std;

char ar[200][200];
string s;

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> s;
		int flag = 0;
		int ct = 0;
		for (int j = 0; j < 5; j++) {
			flag = 0;
			for (int i = 0; i < s.size() * 4 + 1; i++) {
				if (j == 0) {
					if (i == 0 || i == 1) {
						ar[j][i] = '.';
					}
					if (flag == 0 && i != 0 && i != 1) {
						ar[j][i] = '#';
						flag++;
					}
					else if (flag == 1 && i != 0 && i != 1) {
						ar[j][i] = '.';
						flag++;
					}
					else if (flag == 2 && i != 0 && i != 1) {
						ar[j][i] = '.';
						flag++;
					}
					else if (flag == 3 && i != 0 && i != 1) {
						ar[j][i] = '.';
						flag = 0;
					}
				}
				else if (j == 1) {
					if (flag == 0) {
						ar[j][i] = '.';
						flag++;
					}
					else if (flag == 1) {
						ar[j][i] = '#';
						flag = 0;
					}
				}
				else if (j == 2) {
					if (flag == 0) {
						ar[2][i] = '#';
						flag++;
					}
					else if (flag == 1) {
						ar[2][i] = '.';
						flag++;
					}
					else if (flag == 2) {
						ar[2][i] = s[ct];
						flag++;
						ct++;
					}
					else if (flag == 3) {
						ar[2][i] = '.';
						flag = 0;
					}
				}
				else if (j==3) {
					if (flag == 0) {
						ar[j][i] = '.';
						flag++;
					}
					else if (flag == 1) {
						ar[j][i] = '#';
						flag = 0;
					}
				}
				else if (j == 4) {
					if (i == 0 || i == 1) {
						ar[j][i] = '.';
					}
					if (flag == 0 && i != 0 && i != 1) {
						ar[j][i] = '#';
						flag++;
					}
					else if (flag == 1 && i != 0 && i != 1) {
						ar[j][i] = '.';
						flag++;
					}
					else if (flag == 2 && i != 0 && i != 1) {
						ar[j][i] = '.';
						flag++;
					}
					else if (flag == 3 && i != 0 && i != 1) {
						ar[j][i] = '.';
						flag = 0;
					}
				}
			}
		}
		for (int j = 0; j < 5; j++) {
			for (int i = 0; i < s.size() * 4 + 1; i++) {
				cout << ar[j][i];
			}
			cout << endl;
		}
	}
	return 0;
}