
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

int arr[1111][1111];
int dp[1111][1111];
void solve()
{
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	int n, q; cin >> n >> q;
	vector<pii> v(n);
	for (auto& u : v)
	{
		cin >> u.first >> u.second;
		arr[u.first][u.second]++;
	}

	for (int i = 1; i < 1001; i++)
	{
		for (int j = 1; j < 1001; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i - 1][j - 1] * (i - 1) * (j - 1);
		}
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << dp[i][j] << " ";
		}cout << "\n";
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


