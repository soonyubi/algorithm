
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

int n, m;

vector<int> adj[20001];

vector<vector<int>> SCC;

int DFS_cnt = 1;
int DFS_num[20001];
int DFS_min[20001];
int SCC_num[200001];
int visited[20001];
vector<int> stk;

int f(int x)
{
	if (x > 0) return x;
	return -x + n;
}
void dfs(int v)
{
	visited[v] = 1;
	DFS_num[v] = DFS_min[v] = DFS_cnt++;
	stk.push_back(v);

	for (auto nv : adj[v])
	{
		if (!DFS_num[nv]) dfs(nv);
		if (visited[nv]) DFS_min[v] = min(DFS_min[v], DFS_min[nv]);
	}

	if (DFS_min[v] == DFS_num[v])
	{
		SCC.emplace_back();
		while (true)
		{
			int u = stk.back();
			SCC.back().push_back(u);
			visited[u] = 0;
			stk.pop_back();

			SCC_num[u] = SCC.size() - 1;
			if (u == v) break;
		}
		//sort(SCC.back().begin(), SCC.back().end());
	}
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

	for (int i = 1; i <= 2 * n; i++)
	{
		if(!DFS_num[i]) dfs(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (SCC_num[i] == SCC_num[i + n]) // x -> ~x 이고 ~x -> x 인 상황
		{
			cout << "0\n";
			return;
		}
	}

	cout << "1\n";
	

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


