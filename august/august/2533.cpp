
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
const int maxn = 1e6 + 1;
int dp[maxn][2];
vector<int> adj[maxn];
int in[maxn];
bool visited[maxn];
void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		in[u]++;
		in[v]++;
	}
	queue<int> q;
	int root = -1;
	for (int i = 1; i <= n; i++) dp[i][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 1)
		{
			root = i;
			
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		
		for (auto nv : adj[v])
		{
			if (visited[nv]) continue;

			dp[nv][0] += dp[v][1];
			dp[nv][1] += min(dp[v][0], dp[v][1]);

			if (--in[nv] == 1)
			{
				q.push(nv);
				visited[nv] = true;
				root = nv;
			}
		}
	}
	cout << min(dp[root][0], dp[root][1]) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


