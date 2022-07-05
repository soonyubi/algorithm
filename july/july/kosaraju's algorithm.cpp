
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


vector<int> adj[10001];
vector<int> adjT[10001];
int visited[10001];
vector<int> stk;
vector<vector<int>> SCC;

void dfs(int x)
{
	visited[x] = 1;
	for (auto nv : adj[x])
	{
		if (!visited[nv]) dfs(nv);
	}
	stk.push_back(x);
}

void dfs2(int x)
{
	visited[x] = 1;
	SCC.back().push_back(x);

	for (auto nv : adjT[x])
	{
		if (!visited[nv])
		{
			dfs2(nv);
		}
	}
}
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adjT[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i])
		{
			
			dfs(i);
		}
	}

	memset(visited, 0, sizeof(visited));
	
	while (!stk.empty())
	{
		int u = stk.back();
		stk.pop_back();

		if (!visited[u])
		{
			SCC.emplace_back();
			dfs2(u);

			sort(SCC.back().begin(), SCC.back().end());

		}
		
	}
	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << "\n";
	for (auto& u : SCC)
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


