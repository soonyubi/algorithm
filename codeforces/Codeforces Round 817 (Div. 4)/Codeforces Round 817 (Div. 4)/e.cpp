
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


ll dp[1111][1111];
void solve()
{
	
	memset(dp, 0, sizeof(dp));
	int n, q; cin >> n >> q;
	vector<pll> v(n);
	for (auto& u : v)
	{
		cin >> u.first >> u.second;
		dp[u.first][u.second] += u.first * u.second;
	}

	for (int i = 1; i < 1001; i++)
	{
		for (int j = 1; j < 1001; j++)
		{
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	for (int i = 0; i < q; i++)
	{
		int a, b, c, d; cin >> a >> b >> c >> d; c--, d--;
		cout << dp[c][d] - dp[a][d] - dp[c][b] + dp[a][b] << "\n";
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


