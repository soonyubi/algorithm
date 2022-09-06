
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

ll dp[33][33];
string ans(ll n, ll m,ll idx)
{
	string ret = "";
	if (n == 0)
	{
		return "";
	}
	if (idx <= dp[n - 1][m])
	{
		ret = "0" + ans(n - 1, m, idx);
	}
	else
	{
		ret = "1" + ans(n - 1, m - 1, idx - dp[n - 1][m]);
	}

	return ret;
}
void solve()
{
	ll n, l, idx; cin >> n >> l >> idx;

	for (int i = 0; i < 33; i++) {
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	for (int i = 1; i < 33; i++)
	{
		for (int j = 1; j < 33; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	cout << ans(n, l, idx) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


