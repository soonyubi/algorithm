
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
struct info
{
	int dest;
	int cost;
	int time;
};
vector<info> adj[101];
int visited[101][10001];
const int inf = 1e9;
struct compare
{
	bool operator()(info& a,info& b)
	{
		return a.time > b.time;
	}
};
void solve()
{
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int u, v, c, d; cin >> u >> v >> c >> d;
		adj[u].push_back({ v,c,d });
	}
	for (int i = 0; i < 101; i++) for (int j = 0; j < 10001; j++) visited[i][j] = inf;
	queue<info> pq;
	pq.push({ 1,0,0 });
	visited[1][0] = 0;

	while (!pq.empty())
	{
		int v = pq.front().dest;
		int c = pq.front().cost;
		int t = pq.front().time;
		pq.pop();
		
		
		if (visited[v][c] < t) continue;

		for (auto x : adj[v])
		{
			int nv = x.dest;
			int nc = c + x.cost;
			int nt = visited[v][c] + x.time;
			
			if (nc > 10000) continue;
			if (visited[nv][nc] > nt)
			{
				visited[nv][nc] = nt;
				pq.push({ nv,nc,nt });
			}
		}
	}
	
	
	int mn = inf;
	for (int i = 0; i <= m; i++)
	{
		mn = min(mn, visited[n][i]);
	}
	if (mn == inf) cout << "Poor KCM\n";
	else cout << mn << "\n";

	for (int i = 1; i <= n; i++)
	{
		adj[i].clear();
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


