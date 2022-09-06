
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

int dp[11111][11];
void solve()
{
	memset(dp, 1e9 + 8, sizeof(dp));
	int n; cin >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	for (int i = 1; i <= n; i++)
	{
		char c; cin >> c;
		a[i] = c - '0';
	}
	for (int i = 1; i <= n; i++)
	{
		char c; cin >> c;
		b[i] = c - '0';
	}

	for (int i = 0; i < 10; i++) dp[0][i] = i;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int lcnt = (b[i] - a[i] - j + 20) % 10;
			int rcnt = 10 - lcnt;
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + rcnt);
			dp[i][(j + lcnt) % 10] = min(dp[i][(j + lcnt) % 10], dp[i - 1][j] + lcnt);
		}
	}
	int ans = 1e9;
	for (int i = 0; i < 10; i++) ans = min(ans, dp[n][i]);
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


