//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int ar[9];
//int vi[9];
//int ans[7];
//bool flag;
//
//void input() {
//	for (int i = 0; i < 9; i++) cin >> ar[i];
//}
//
//void pro(int i, int ct, int sum) {
//	if (ct == 7) {
//		if (sum == 100) {
//			int qq = 0;
//			for (int w = 0; w < 9; w++) {
//				if (vi[w] == 1) {
//					ans[qq] = ar[w];
//					qq++;
//				}
//			}
//			flag = true;
//		}
//		return;
//	}
//
//	for (int w = 0; w < 9; w++) {
//		//if (flag) break;
//		if (vi[w] == 0) {
//			vi[w] = 1;
//			pro(w, ct + 1, sum + ar[w]);
//			vi[w] = 0;
//		}
//	}
//}
//
//void solve() {
//	vi[0] = 1;
//	for (int i = 0; i < 9; i++) {
//		pro(i, 1, ar[0]);
//	}
//	sort(ans, ans + 7);
//}
//
//int main() {
//	input();
//	solve();
//	for (int i = 0; i < 7; i++) cout << ans[i] << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> v;
//int vi[9];
//vector<int> ans;
//bool flag = false;
//
//void input() {
//	int a;
//	for (int i = 0; i < 9; i++) {
//		cin >> a;
//		v.push_back(a);
//	}
//}
//void pro(int cnt, int sum, int i) {
//	if (cnt == 7) {
//		if (sum == 100) {
//			for (int x = 0; x < v.size(); x++) {
//				if (vi[x] == 1) ans.push_back(v[x]);
//			}
//			flag = true;
//		}
//		return;
//	}
//
//	for (int x = i; x < 9; x++) {
//		if (flag) break;
//		if (vi[x] == 0) {
//			vi[x] = 1;
//			pro(cnt + 1, sum + v[x], x);
//			vi[x] = 0;
//		}
//	}
//
//}
//
//void solve() {
//	for (int i = 0; i < 3; i++) {
//		vi[i] = 1;
//		pro(1, v[i]);
//		vi[i] = 0;
//	}
//	sort(ans.begin(), ans.end());
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << endl;
//	}
//
//}
//
//int main() {
//	input();
//	solve();
//}

#include <iostream>
#include <vector>

using namespace std;

int ar[3] = { 11,12,13};
bool vi[3];
vector<int> v;

void pro(int ct)
{
	if (ct == 3)
	{
		return;
	}

	for (int w = 0; w < 3; w++)
	{
		//if (!vi[w])
		{
			vi[w] = true;
			v.push_back(ar[w]);
			pro(ct + 1);
			v.pop_back();
			vi[w] = false;
		}
	}
}

int main()
{
	pro(0);
	return 0;
}