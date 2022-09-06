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

int n, m, k;
const int S = 2001, T = 2002;
const int INF = 987654321;

const int maxn = 2020;
struct Node
{
	int nv;
	int flow;
	int ridx; // 역방향 간선의 인덱스
};
vector<Node> adj[maxn];

int cache[maxn];
int par[maxn], pidx[maxn];

bool bfs() // 최단 경로가 존재하면 true
{
	memset(cache, 0, sizeof(cache));
	queue<int> q;
	cache[S] = 1; q.push(S);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++)
		{
			int nv = adj[v][i].nv;
			int flow = adj[v][i].flow;

			if (cache[nv]) continue;
			if (!flow) continue;

			par[nv] = v;
			pidx[nv] = i;
			cache[nv] = 1;
			q.push(nv);
		}
	}

	return cache[T];
}
int getFlow(int v, int cf)
{
	if (v == S) return cf;

	int pv = par[v];
	int& flow = adj[pv][pidx[v]].flow;
	int& rflow = adj[v][adj[pv][pidx[v]].ridx].flow;

	int res = getFlow(par[v], min(cf, flow));

	flow -= res;
	rflow += res;

	return res;
}
void solve()
{
	cin >> n >> m;
	//adj[S].push_back({ 0,k,(int)adj[0].size() });
	//adj[0].push_back({ S,0,(int)adj[S].size() - 1 });

	for (int i = 1; i <= n; i++)
	{
		adj[S].push_back({ i,2,(int)adj[i].size() });
		adj[i].push_back({ S,0,(int)adj[S].size() - 1 });

		adj[0].push_back({ i,INF,(int)adj[i].size() });
		adj[i].push_back({ 0,0,(int)adj[0].size() - 1 });
	}
	for (int i = n + 1; i <= n + m; i++)
	{
		adj[i].push_back({ T,1,(int)adj[T].size() });
		adj[T].push_back({ i,0,(int)adj[i].size() - 1 });
	}

	for (int i = 1; i <= n; i++)
	{
		int sz; cin >> sz;
		for (int j = 0; j < sz; j++)
		{
			int w; cin >> w; w += n;
			adj[i].push_back({ w,INF,(int)adj[w].size() });
			adj[w].push_back({ i,0,(int)adj[i].size() - 1 });
		}
	}

	int ans = 0;
	while (bfs())
	{
		memset(cache, 0, sizeof(cache));
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


