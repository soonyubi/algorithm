
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
bool finished[100001];
vector<int> stk;
vector<vector<int>> SCC;
set<int> sccAdj[100001];
int indegree[100001];

void init()
{
	cnt = 0; stk.clear();
	
	for (auto u : SCC)
	{
		u.clear();
	}
	SCC.clear();
	for (int i = 0; i < 100001; i++)
	{
		adj[i].clear();
		sccAdj[i].clear();
		dfs_num[i] = scc_num[i] = finished[i] = indegree[i] = false;
	}
}
int dfs(int v)
{
	dfs_num[v] = ++cnt;
	stk.push_back(v);

	int result = dfs_num[v];
	for (auto nv : adj[v])
	{
		// 방문하기 전
		if (!dfs_num[nv]) result = min(result, dfs(nv));
		// 방문은 했는데, SCC로 추출이 안된경우
		else if (!finished[nv]) result = min(result, dfs_num[nv]);
	}

	// 자신과 자신의 자손들이 갈수있는 최대 조상이 자신
	if (result == dfs_num[v])
	{
		SCC.emplace_back();
		while (1)
		{
			int t = stk.back(); stk.pop_back();
			SCC.back().push_back(t);
			finished[t] = true;
			scc_num[t] = SCC.size() - 1;

			if (t == v) break;
		}
		//sort(SCC.back().begin(), SCC.back().end());
	}
	return result;

}

void dfs2(int v)
{
	finished[v] = true;
	for (auto nv : sccAdj[v])
	{
		if (!finished[nv])
		{
			dfs2(nv);
		}
	}
}


void solve()
{
	init();
	int n, m; cin >> n >> m;
	vector<pii> vv(m);
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		vv[i] = { a,b };
		adj[a].push_back(b);
		
	}

	for (int i = 1; i <= n; i++) if (!dfs_num[i]) dfs(i);

	// sort(SCC.begin(), SCC.end());

	
	for (int i = 1; i <= n; i++)
	{
		for (auto u : adj[i])
		{
			if (scc_num[u] == scc_num[i]) continue;
			indegree[scc_num[u]]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < SCC.size(); i++)
	{
		if (indegree[i] == 0) ans++;
	}


	cout << ans << "\n";



	
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


