#include <iostream>
#define SZ 10001

using namespace std;

struct Node {
	int parent = 0;
	int left = 0;
	int right = 0;
};

int t, V, E, s1, s2, max_idx;

int count_node(Node tree[], int node) {
	int ans = 1;

	if (tree[node].left != 0) ans += count_node(tree, tree[node].left);
	if (tree[node].right != 0) ans += count_node(tree, tree[node].right);

	return ans;
}

int main() {
	cin >> t;;

	for (int k = 0; k < t; k++) {
		Node tree[SZ];
		bool check[SZ] = { false, };
		cin >> V >> E >> s1 >> s2;
		int x, y;
		for (int i = 0; i < E; i++) {
			cin >> x >> y;
			if (tree[x].left == 0) {
				tree[x].left = y;
			}
			else {
				tree[x].right = y;
			}

			tree[y].parent = x;
		}

		int cur = tree[s1].parent;
		while (true) {
			check[cur] = true;
			if (cur == 1) break;
			cur = tree[cur].parent;
		}

		cur = tree[s2].parent;
		while (true) {
			if (check[cur]) {
				cout << "#" << k + 1 << " " << cur << " " << count_node(tree, cur) << endl;
				break;
			}
			cur = tree[cur].parent;
		}
	}
}