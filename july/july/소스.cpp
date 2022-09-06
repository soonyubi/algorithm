#include <bits/stdc++.h>
using namespace std;

struct asdf {

	int x, y, z;
};

bool cmp(asdf a, asdf b) {
	return a.x < b.x;
}

const int size1 = 500000 + 10;
asdf arr[size1];
int tree[4 * size1];

int update(int node, int start, int end, int idx, int value) {
	if (idx < start || end < idx) return tree[node];
	if (start == end) return tree[node] = value;
	int mid = (start + end) >> 1;
	return tree[node] = min(
		update(node * 2, start, mid, idx, value),
		update(node * 2 + 1, mid + 1, end, idx, value)
	);
}

int get(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 1e9 + 7;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	return min(
		get(node * 2, start, mid, left, right),
		get(node * 2 + 1, mid + 1, end, left, right)
	);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t; arr[t].x = i;
	}
	for (int i = 1; i <= n; i++) {
		int t; cin >> t; arr[t].y = i;
	}
	for (int i = 1; i <= n; i++) {
		int t; cin >> t; arr[t].z = i;
	}
	sort(arr + 1, arr + n + 1, cmp);
	for (int i = 1; i <= n; i++) update(1, 1, n, i, 1e9 + 7);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (get(1, 1, n, 1, arr[i].y) > arr[i].z) ans++;
		cout << arr[i].z << " " << get(1, 1, n, 1, arr[i].y) << "\n";
		update(1, 1, n, arr[i].y, arr[i].z);
	}

	cout << ans;
}