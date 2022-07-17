
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
int path[301][301];
vector<int> adj[301];
int dfs_num[301];
int scc_num[301];
int cnt;
vector<int> stk;
bool finished[301];
vector<vector<int>> SCC;
int adj_scc[301][301];

void init()
{
	for (int i = 0; i < SCC.size(); i++) SCC[i].clear();
	SCC.clear();
	cnt = 0; stk.clear();
	for (int i = 0; i < 301; i++)
	{
		adj[i].clear();
		scc_num[i] = dfs_num[i] = 0;
		finished[i] = false;

		for (int j = 0; j < 301; j++) adj_scc[i][j] = false;
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

	if (dfs_num[v] == result)
	{
		SCC.emplace_back();
		while (true)
		{
			int t = stk.back(); stk.pop_back();
			SCC.back().push_back(t);
			finished[t] = true;
			scc_num[t] = SCC.size() - 1;
			if (t == v) break;
		}
	}
	return result;
}
void solve()
{
	init();
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c; cin >> c;
			path[i][j] = c - '0';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (path[i][j]) adj[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}

	// 모든 SCC간의 연결도
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (path[i][j] == 0 || i == j || scc_num[i] == scc_num[j]) continue;
			adj_scc[scc_num[i]][scc_num[j]] = true;
		}
	}

	// i->j , j->k 와 i->k가 공존하면, i->k는 삭제해야됌
	for (int j = 0; j < SCC.size(); j++)
	{
		for (int i = 0; i < SCC.size(); i++)
		{
			for (int k = 0; k < SCC.size(); k++)
			{
				if (adj_scc[i][k] && adj[i][j] && adj[j][k]) adj_scc[i][k] = false;
			}
		}
	}
	vector<pii> ans;
	
	for (int i = 0; i < SCC.size(); i++)
	{
		// SCC 내부에서 사이클
		if (SCC[i].size() > 1)
		{
			for (int j = 0; j < SCC[i].size(); j++)
			{
				ans.push_back({ SCC[i][j],SCC[i][(j + 1) % SCC[i].size()] });
			}
		}


		// SCC간 
		for (int j = 0; j < SCC.size(); j++)
		{
			if (i == j) continue;
			if (adj_scc[i][j])
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


