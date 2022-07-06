
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<int, int>
#define pll pair<ll, ll>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int cnt;
int dfs_num[10001];
int scc_num[10001];
bool finished[10001];
vector<int> stk;
vector<vector<int>> SCC;
vector<int> adj[10001];

int dfs(int x)
{
	dfs_num[x] = ++cnt;
	stk.push_back(x);

	int result = dfs_num[x];
	for (auto nv : adj[x])
	{
		// 아직 방문하지 않음
		if (!dfs_num[nv]) result = min(result, dfs(nv));
		// 방문은 했는데 scc로 추출되지 않은 이웃
		else if (!finished[nv]) result = min(result, dfs_num[nv]);
	}

	// 자신의 자손들이 갈 수 있는 가장 높은 조상이 자신이라면,
	if (result == dfs_num[x])
	{
		SCC.emplace_back();
		while (true)
		{
			int t = stk.back(); stk.pop_back();
			SCC.back().push_back(t);
			finished[t] = true;
			scc_num[t] = SCC.size() - 1;
			if (t == x) break;
		}
		sort(SCC.back().begin(), SCC.back().end());

	}
	return result;
}
void solve()
{
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}

	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << "\n";
	for (auto u : SCC)
	{
		for (auto x : u)
		{
			cout << x << " ";
		}cout << "-1\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


