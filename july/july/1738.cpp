
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
vector<pll> adj[101];
vector<int> from[101];
bool floyd[101][101];
bool visited[101];
int n, m;
const ll inf = 1e9;
void go()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (floyd[j][i] && floyd[i][k]) floyd[j][k] = true;
			}
		}
	}
}
vector<int> bellman(int s)
{
	vector<ll> dist(n + 1, inf);
	dist[s] = 0;
	from[s].push_back(s);
	bool chk = false;

	for (int i = 0; i < n; i++)
	{
		chk = false;
		for (int v = 1; v <= n; v++)
		{
			if (dist[v] == inf) continue;
			for (auto it : adj[v])
			{
				int nv = it.first;
				int nc = it.second;

				if (dist[nv] > dist[v] + nc)
				{
					if (i == n - 1)
					{
						if (floyd[1][v] && floyd[v][n])
						{
							from[n].clear();
							return from[n];
						}
					}
					else
					{
						dist[nv] = dist[v] + nc;
						from[nv] = from[v];
						from[nv].push_back(nv);
						chk = true;
					}
				}
			}
		}
		if (chk == false) break;
	}
	if (chk == true) from[n].clear();
	return from[n];
}
void solve()
{
	 cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ v,-c });
		floyd[u][v] = true;
	}
	go();

	vector<int> ans = bellman(1);

	if (ans.size() == 0) cout << "-1\n";
	else
	{
		for (auto u : ans)
		{
			cout << u << " ";
		}cout << "\n";
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


