
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
const int maxn = 5001;
vector<int> adj[maxn];
int dfs_num[maxn];
int scc_num[maxn];
bool finished[maxn];
vector<int> stk;
vector<vector<int>> SCC;
int cnt;
int out[maxn];

int n, m;

void init()
{
	for (int i = 0; i < SCC.size(); i++) SCC[i].clear();
	SCC.clear();
	stk.clear();
	cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		dfs_num[i] = scc_num[i] = finished[i] = out[i] = 0;
		adj[i].clear();
	}
}
// SCC 의 outdegree가 0인것
int dfs(int v)
{
	dfs_num[v] = ++cnt;
	stk.push_back(v);
	int result = dfs_num[v];

	for (auto nv : adj[v])
	{
		if (!dfs_num[nv]) result = min(result, (dfs(nv)));
		else if (!finished[nv]) result = min(result, dfs_num[nv]);
	}

	if (result == dfs_num[v])
	{
		SCC.emplace_back();
		while (true)
		{
			int t = stk.back(); stk.pop_back();
			finished[t] = true;
			scc_num[t] = SCC.size() - 1;
			SCC.back().push_back(t);
			if (t == v) break;
		}
		sort(SCC.back().begin(), SCC.back().end());
	}
	return result;
}
void solve()
{
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}

	for (int i = 0; i < SCC.size(); i++)
	{
		for (auto u : SCC[i])
		{
			for (auto x : adj[u])
			{
				if (scc_num[x] != scc_num[u]) out[i]++;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < SCC.size(); i++)
	{
		if (out[i] == 0)
		{
			for (auto u : SCC[i])
			{
				ans.push_back(u);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (auto u : ans)
	{
		cout << u << " ";
	}cout << "\n";

	init();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true)
	{
		cin >> n; if (n == 0) break;
		cin >> m;
		solve();
	}
	return 0;
}


