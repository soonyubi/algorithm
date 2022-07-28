
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
int dfs_num[100001];
int scc_num[100001];
vector<int> adj[100001];
bool finished[100001];
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
		else if (finished[nv]) result = min(result, dfs_num[nv]);
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
	else return -x + n;
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
	cout << "yes\n";
	for (int i = 1; i <= 2 * n; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (scc_num[i] == scc_num[i + n])
		{
			cout << "0\n";
			return;
		}
	}

	cout << "1\n";





	// ~x -> x 인경우 x는 true
	// x -> ~x인 경우 x는 false
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


