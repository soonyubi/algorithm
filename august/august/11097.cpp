
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
int floyd[333][333];
int dfs_num[333];
int scc_num[333];
bool finished[333];
vector<int> adj[333];
int cnt;
vector<int> stk;
vector<vector<int>> SCC;
int n; 
bool floyd_scc[333][333];

void init()
{
	for (int i = 0; i < SCC.size(); i++) SCC[i].clear();
	SCC.clear();
	cnt = 0;
	stk.clear();
	for (int i = 0; i <= n; i++)
	{
		dfs_num[i] = scc_num[i] = finished[i] = 0;
		adj[i].clear();
		for (int j = 0; j <= n; j++)
		{
			floyd_scc[i][j] = floyd[i][j] = 0;
		}
	}
	
}
int dfs(int v)
{
	dfs_num[v] = ++cnt;
	stk.push_back(v);

	int result = dfs_num[v];
	for (auto nv : adj[v])
	{
		if (!dfs_num[nv]) result = min(result, dfs(nv));
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
	}

	return result;
}
void solve()
{
	
	cin >> n;
	init();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c; cin >> c;
			floyd[i][j] = c - '0';
			if (i!=j&&floyd[i][j] == 1) adj[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (floyd[i][j] == 0 || i == j || scc_num[i] == scc_num[j]) continue;
			floyd_scc[scc_num[i]][scc_num[j]] = true;
		}
	}
	int k = SCC.size();
	

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int l = 0; l < k; l++)
			{
				if (floyd_scc[j][l] && floyd_scc[j][i] && floyd_scc[i][l])
				{
					floyd_scc[j][i] = floyd_scc[i][l] = true;
					floyd_scc[j][l] = false;
				}
			}
		}
	}
	vector<pii> ans;
	for (int i=0;i<SCC.size();i++)
	{
		if (SCC[i].size() > 1)
		{
			for (int j = 0; j < SCC[i].size(); j++)
			{
				ans.push_back({ SCC[i][j], SCC[i][(j + 1) % SCC[i].size()] });
			}
		}
		for (int j = 0; j < SCC.size(); j++)
		{
			if (i == j) continue;
			if (floyd_scc[i][j])
			{
				ans.push_back({ SCC[i][0],SCC[j][0] });
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto u : ans)
	{
		cout << u.first << " " << u.second << "\n";
	} 
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


