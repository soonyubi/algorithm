
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

int n, m;

vector<int> adj[10001];

vector<vector<int>> SCC;

int DFS_cnt = 1;
int DFS_num[10001];
int DFS_min[10001];
int visited[10001];
vector<int> stk;
void dfs(int v)
{
	visited[v] = 1;
	DFS_num[v] = DFS_min[v] = DFS_cnt++;
	stk.push_back(v);

	for (auto nv : adj[v])
	{
		if (!DFS_num[nv]) dfs(nv);
		if (visited[nv]) DFS_min[v] = min(DFS_min[v], DFS_min[nv]);
	}

	if (DFS_min[v] == DFS_num[v])
	{
		SCC.emplace_back();
		while (true)
		{
			int u = stk.back();
			SCC.back().push_back(u);
			visited[u] = 0;
			stk.pop_back();

			if (u == v) break;
		}
		sort(SCC.back().begin(), SCC.back().end());
	}
}
void solve()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!DFS_num[i]) dfs(i);
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


