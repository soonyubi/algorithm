
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
const int MAXN = 20001;
int n, m, cnt;
vector<int> adj[MAXN];
int DFS_num[MAXN];
int SCC_num[MAXN];
bool finished[MAXN];
vector<int> stk;
vector<vector<int>> SCC;
int f(int x)
{
	if (x > 0) return x;
	return -x + n;
}
int dfs(int v)
{
	DFS_num[v] = ++cnt;
	stk.push_back(v);

	int result = DFS_num[v];
	for (auto nv : adj[v])
	{
		if (!DFS_num[nv]) result = min(result, dfs(nv));
		else if (!finished[nv]) result = min(result, DFS_num[nv]);
	}

	if (result == v)
	{
		SCC.emplace_back();
		while (true)
		{
			int t = stk.back(); stk.pop_back();
			SCC.back().push_back(t);
			finished[t] = true;
			SCC_num[t] = SCC.size() - 1;
			if (t == v) break;
		}
		sort(SCC.back().begin(), SCC.back().end());
	}

	return result;
}
void dfs2(int v)
{
	finished[v] = true;
	for (auto u : SCC[v])
	{
		for (int nv : adj[u])
		{
			int ns = SCC_num[nv];
			if (finished[ns]) continue;
			dfs2(ns);
		}
	}
	stk.push_back(v);
}
void solve()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[f(-u)].push_back(f(v));
		adj[f(-v)].push_back(f(u));
	}

	for (int i = 1; i <= 2*n; i++)
	{
		if (!DFS_num[i]) dfs(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (SCC_num[i] == SCC_num[i + n])
		{
			cout << "0\n";
			return;
		}
	}

	cout << "1\n";
	memset(finished, false, sizeof(finished));
	for (int i = 0; i < SCC.size(); i++)
	{
		if (!finished[i]) dfs2(i);
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


