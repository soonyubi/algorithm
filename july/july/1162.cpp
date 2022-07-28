
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

ll visited[10001][21]; // i번째도로에 도달했을 때 k만큼 포장했을 경우의 최소시간
vector<pll> adj[10001];
const ll inf = LLONG_MAX;
struct compare
{
	bool operator()(pair<ll, pll> a, pair<ll, pll> b)
	{
		return a.first > b.first;
	}
};
void solve()
{
	ll n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	priority_queue< pair<ll, pll>, vector<pair<ll, pll>>, compare> pq;
	pq.push({ 0,{1,0} });
	visited[1][0] = 0;
	for (int i = 0; i < 10001; i++) for (int j = 0; j < 21; j++) visited[i][j] = inf;
	
	while (!pq.empty())
	{

		ll v = pq.top().second.first;
		ll p = pq.top().second.second;
		ll c = pq.top().first;
		
		pq.pop();

		if (visited[v][p] < c) continue;

		for (auto x : adj[v])
		{
			ll nv = x.first;
			ll nc = x.second + c;
			ll np = p;
			// 포장 x
			if (visited[nv][np] > nc)
			{
				visited[nv][np] = nc;
				pq.push({ nc,{nv,np} });
			}

			// 포장 o
			np++;
			if (np > k) continue;
			nc = c;
			if (visited[nv][np] > nc)
			{
				visited[nv][np] = nc;
				pq.push({ nc,{nv,np} });
			}

		}
	}
	ll ans = inf;
	for (int i = 0; i <= k; i++)
	{
		
		ans = min(ans, visited[n][i]);
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


