
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
vector<int> adj[2020];
int cnt;
int dfs_num[2020];
int scc_num[2020];
bool finished[2020];
vector<int> stk;
vector<vector<int>> SCC;
int n, m;

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
int f(int x)
{
	if (x > 0) return x;
	else return -x + n;
}
void solve()
{
	//cin >> n >> m;
	

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[f(-u)].push_back(f(v));
		adj[f(-v)].push_back(f(u));
	}
	//adj[f(-1)].push_back(f(1));
	
	for (int i = 1; i <= 2 * n; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (scc_num[i] == scc_num[i + n])
		{
			flag = false;
			break;
		}
	}
	if (scc_num[f(1)] > scc_num[f(-1)])
	{
		flag = false;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << scc_num[i] << " " << scc_num[i + n] << "\n";
	}

	if (flag) cout << "yes\n";
	else cout << "no\n";
	for (int i = 0; i < SCC.size(); i++)
	{
		SCC[i].clear();
	}
	SCC.clear();
	stk.clear();
	cnt = 0;
	for (int i = 0; i <= 2*n; i++)
	{
		dfs_num[i] = scc_num[i] = finished[i] = 0;
		adj[i].clear();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> n >> m) solve();
	return 0;
}


