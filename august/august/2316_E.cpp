
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

const int maxn = 401;
const int S = 1, T = 2;
const int INF = 987654321;

struct Node
{
	int nv;
	int flow;
	int ridx;
};
vector<Node> adj[maxn];
bool visited[maxn];
int par[maxn]; int pidx[maxn];
bool bfs()
{
	visited[S] = true;
	queue<int> q; q.push(S);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		for (int i = 0; i < adj[v].size(); i++)
		{
			int nv = adj[v][i].nv;
			int flow = adj[v][i].flow;

			if (visited[nv]) continue;
			if (!flow) continue;

			par[nv] = v;
			pidx[nv] = i;
			visited[nv] = true;
			q.push(nv);
		}
	}
	return visited[T];
}
int getFlow(int v, int cf)
{
	if (v == S) return cf;

	int pv = par[v];
	int& flow = adj[pv][pidx[v]].flow;
	int& rflow = adj[v][adj[pv][pidx[v]].ridx].flow;

	int res = getFlow(pv, min(cf, flow));

	flow -= res;
	rflow += res;
	return res;
}
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back({ v,1,(int)adj[v].size() });
		adj[v].push_back({ u,1,(int)adj[u].size() - 1 });
	}

	int ans = 0;
	while (bfs())
	{
		memset(visited, false, sizeof(visited));
		int res = getFlow(T, INF);
		ans += res;
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


