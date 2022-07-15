
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
const int MAX = 1e5 + 1;
int w[MAX];
vector<int> adj[MAX];
int degree[MAX];
bool visited[MAX];
int dp[MAX][2];
bool chk[MAX];
void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}

	queue<int> q;
	int root = -1;

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 1)
		{
			q.push(i);
			root = i;
		}
	}
	
	for (int i = 1; i <= n; i++) dp[i][1] = w[i];
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		visited[v] = true;

		for (auto nv : adj[v])
		{
			if (visited[nv]) continue;
			// nv가 포함되려면, v는 무조건 포함 x
			
			dp[nv][1] += dp[v][0];
			
			// nv가 포함안되려면, v는 포함되든 안되든 상관 x
			dp[nv][0] += max(dp[v][0], dp[v][1]);
			if(dp[v][0]<dp[v][1])
			if (--degree[nv] == 1)
			{
				q.push(nv);
				root = nv;
			}
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i][0] < dp[i][1]) ans.push_back(i);
	}
	
	cout << max(dp[root][0], dp[root][1]) << "\n";
	for (auto u : ans) cout << u << " "; cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


