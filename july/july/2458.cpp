
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

bool dp[501][501];
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		dp[u][v] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				// j->i 갈수있고, i-> k 갈수있으면 j->k true
				if (j == k) continue;
				if (dp[j][i] && dp[i][k]) dp[j][k] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt1 = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (dp[j][i]) cnt1++;
		}
		int cnt2 = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (dp[i][j]) cnt2++;
		}
		if (cnt1 + cnt2 == n-1) ans++;
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


