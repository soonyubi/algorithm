
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
vector<int> adj[100001];
int dfs_num[100001];
int scc_num[100001];
int in[100001];
bool finished[100001];
vector<int> stk;
vector<vector<int>> SCC;

int dfs(int x)
{
	dfs_num[x] = ++cnt;
	stk.push_back(x);

	int result = dfs_num[x];
	for (auto nv : adj[x])
	{
		if (!dfs_num[nv]) result = min(result, dfs(nv));
		else if (!finished[nv]) result = min(result, dfs_num[nv]);
	}

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
		//sort(SCC.back().begin(), SCC.back().end());
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
	
	for (int i = 0; i < n; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}

	for (int i = 0; i < n; i++)
	{
		for (auto u : adj[i])
		{
			if (scc_num[i] != scc_num[u]) in[scc_num[u]]++;
		}
	}

	int ans = -1;
	int cnt = 0;
	for (int i = 0; i < SCC.size(); i++)
	{
		if (in[i] == 0)
		{
			ans = i;
			cnt++;
		}
	}

	if (cnt > 1)
	{
		cout << "Confused\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (scc_num[i] == ans) cout << i << "\n";
		}
	}
	cout << "\n";

	cnt = 0;
	for (int i = 0; i < SCC.size(); i++)
	{
		SCC[i].clear();
	}
	SCC.clear();
	for (int i = 0; i < n; i++)
	{
		adj[i].clear();
		in[i] = dfs_num[i] = scc_num[i] = 0;
		finished[i] = false;
	}
	stk.clear();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}


