
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
const int maxn = 2e5 + 1;
int dp[maxn][20];

void getTable()
{
	for (int i = 1; i < maxn; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			dp[i][j] = (((1 << j) & i)?1:0) + dp[i - 1][j];
		}
	}
}
void solve()
{
	int l, r; cin >> l >> r;

	int n = r - l + 1;
	int ans = n;
	for (int i = 0; i < 20; i++)
	{
		int one = dp[r][i] - dp[l - 1][i];
		int zero = n - one;
		ans = min(ans, zero);
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getTable();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


