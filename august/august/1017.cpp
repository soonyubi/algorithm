#include <bits/stdc++.h>
using namespace std;

int n;
int isP[2020];
int par[2020];
int chk[2020];
vector<int> ans, a, b;
vector<int> g[2020];
int bias = 50;

bool flag = 0;

int fixA, fixB;

void era() {
	for (int i = 2; i < 2020; i++) isP[i] = 1;
	for (int i = 1; i < 2020; i++) {
		if (!isP[i]) continue;
		for (int j = i + i; j < 2020; j += i) isP[j] = 0;
	}
}

bool dfs(int v) {
	for (auto i : g[v]) {
		if (chk[i]) continue;
		if (i == fixA || i == fixB) continue;
		chk[i] = 1;
		if (!isP[a[v] + b[i - bias]]) continue;
		if (par[i] == -1 || dfs(par[i])) {
			par[i] = v; return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	era();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		if (i == 1 && t % 2 == 0) flag = 1;
		if (t & 1) a.push_back(t);
		else b.push_back(t);
	}
	if (a.size() != b.size()) {
		cout << -1; return 0;
	}

	if (flag) swap(a, b);

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (isP[a[i] + b[j]]) g[i].push_back(j + bias);
		}
	}

	for (int pre = 0; pre < b.size(); pre++) {
		memset(par, -1, sizeof par);
		if (!isP[a[0] + b[pre]]) continue;
		int match = 1;
		par[pre + bias] = 0;
		fixA = 0, fixB = pre + bias;

		for (int i = 1; i < a.size(); i++) {
			memset(chk, 0, sizeof chk);
			chk[0] = chk[pre + bias] = 1;
			match += dfs(i);
		}

		if (match != b.size()) continue;
		ans.push_back(b[pre]);
	}
	if (ans.size()) {
		sort(ans.begin(), ans.end());
		for (auto i : ans) cout << i << " ";
	}
	else cout << -1;
}