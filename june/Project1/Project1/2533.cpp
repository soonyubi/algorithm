
/*
*   Time :
*   Subject : tree dp
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int MAX = 1e6 + 1;

vector<int> adj[MAX];
bool visited[MAX];
int degree[MAX];
int dp[MAX][2];

void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	
	int root = -1;
	queue<int> q;
	for (int i = 1; i <= n; i++) dp[i][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 1)
		{
			q.push(i);
			root = i;
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		visited[cur] = true;

		for (auto u : adj[cur])
		{
			if (visited[u]) continue;
			dp[u][0] += dp[cur][1];
			dp[u][1] += min(dp[cur][0], dp[cur][1]);
			if (--degree[u] == 1)
			{
				q.push(u);
				root = u;
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


