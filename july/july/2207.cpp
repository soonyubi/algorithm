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
int dfs_num[20001];
int scc_num[20001];
vector<int> adj[20001];
bool finished[20001];
vector<int> stk;
vector<vector<int>>SCC;
int n, m;

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
			SCC.back().push_back(t);
			finished[t] = true;
			scc_num[t] = SCC.size() - 1;
			if (t == v) break;
		}
	}
	return result;
}

int f(int x)
{
	if (x > 0) return x;
	else return -x + m;
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[f(-u)].push_back(f(v));
		adj[f(-v)].push_back(f(u));
	}

	for (int i = 1; i <= 2* m; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}

	for (int i = 1; i <= m; i++)
	{
		if (scc_num[i] == scc_num[i +m])
		{
			cout << "OTL\n";
			return;
		}
	}

	cout << "^_^\n";





	// ~x -> x �ΰ�� x�� true
	// x -> ~x�� ��� x�� false
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

