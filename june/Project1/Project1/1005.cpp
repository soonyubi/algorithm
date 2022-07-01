
/*
*   Time :
*   Subject : 위상정렬
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
int d[1001];
int dp[1001];
int indegree[1001];
vector<int> adj[1001];
void solve()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 0; i < k; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}
	int ans; cin >> ans;

	priority_queue<int> pq;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			dp[i] = d[i];
			pq.push(i);
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (pq.empty())
		{
			cout << "-1\n";
			return;
		}
		
		int v = pq.top();
		pq.pop();

		for (auto u : adj[v])
		{
			dp[u] = max(dp[u], dp[v] + d[u]);
			if (--indegree[u] == 0)
			{
				pq.push(u);
			}
		}
	}

	cout << dp[ans] << "\n";
	for (int i = 1; i <= n; i++)
	{
		adj[i].clear();
		dp[i] = d[i] = indegree[i] = 0;
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


