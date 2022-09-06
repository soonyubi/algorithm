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
int dp[1001][1001];
void solve()
{
	string a, b; cin >> a >> b;
	int n = (int)a.size(); int m = (int)b.size();
	a = '#' + a;
	b = '#' + b;
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			mx = max(mx, dp[i][j]);
		}
	}
	vector<char> stk;
	int i = n, j = m;
	while (dp[i][j] != 0)
	{

		if (dp[i][j] == dp[i - 1][j]) i--;
		else if (dp[i][j] == dp[i][j - 1]) j--;
		else if (dp[i][j] - 1 == dp[i - 1][j - 1])
		{
			stk.push_back(a[i]);
			i--, j--;
		}
	}
	cout << dp[n][m] << "\n";
	reverse(stk.begin(), stk.end());
	for (auto u : stk) cout << u; cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


