
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
const int maxn = 50000;
vector<pll> adj[maxn];
int n, m, f, s, t; 
const ll INF = LLONG_MAX;
struct edge
{
	ll v;
	ll cost;
	int use;
	
};
struct compare
{
	bool operator()(edge a, edge b)
	{
		return a.cost > b.cost;
	}
};
int dijkstra()
{
	vector<vector<ll>> dist(n, vector<ll>(2, INF));
	priority_queue<edge,vector<edge>,compare> pq;
	pq.push({ s,0,0 });
	while (!pq.empty())
	{
		ll v = pq.top().v;
		ll c = pq.top().cost;
		int use = pq.top().use;
		pq.pop();
		if (c > dist[v][use]) continue;
		for (auto x : adj[v])
		{
			ll nv = x.first;
			ll nc = x.second + c;
			if (x.second == 0)
			{
				if (use == 0) continue;
				else
				{
					if (dist[nv][1] > nc)
					{
						dist[nv][1] = nc;
						pq.push({ nv,nc,1 });
					}
				}
			}
			else
			{
				if (dist[nv][use] > nc)
				{
					dist[nv][use] = nc;
					pq.push({ nv,nc,use });
				}
			}

		}
	}

	return min(dist[t][0], dist[t][1]);
}
void solve()
{
	cin >> n >> m >> f >> s >> t;
	for (int i = 0; i < m; i++)
	{
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	for (int i = 0; i < f; i++)
	{
		ll u, v; cin >> u >> v;
		adj[u].push_back({ v,0 });
	}
	ll ans = dijkstra();
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


