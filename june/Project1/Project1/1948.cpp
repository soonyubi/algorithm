
/*
*   Time :
*   Subject : topological sort
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<ll, ll>
#define pll pair<ll, ll>
// ll_MAX ll_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

vector<pll> adj[10001];
vector<ll> from[10001];
ll in[10001];

void solve()
{
	ll n, m; cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		in[v]++;
	}
	ll s, e; cin >> s >> e;
	vector<ll> dist(n + 1, 0);
	priority_queue<ll> pq;
	pq.push(s);
	dist[s] = 0;
	for (ll i = 0; i < n - 1; i++)
	{
		if (pq.empty())
		{
			// cycle
			cout << "-1\n";
			return;
		}

		ll v = pq.top();
		pq.pop();

		for (auto nv : adj[v])
		{
			if (dist[nv.first] < dist[v] + nv.second)
			{
				from[nv.first].clear();
				from[nv.first].push_back(v);
				dist[nv.first] = dist[v] + nv.second;
			}
			else if (dist[nv.first] == dist[v] + nv.second)
			{
				from[nv.first].push_back(v);
				dist[nv.first] = dist[v] + nv.second;
			}
			if (--in[nv.first]== 0)
			{
				pq.push(nv.first);
			}
		}
	}
	vector<bool> visited(n + 1, false);
	queue<ll> q; 
	q.push(e);

	ll cnt = 0;
	while (!q.empty())
	{
		ll x = q.front();
		q.pop();
		if (visited[x]) continue;
		visited[x] = true;

		for (auto u : from[x])
		{
			q.push(u);
			cnt++;
		}
	}
	
	cout << dist[e] << "\n" << cnt << "\n";
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


