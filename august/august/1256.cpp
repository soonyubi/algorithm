
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
ll dp[111][111];

const ll inf = 1e9;
bool flag = true;
string ans(int n, int m, int k)
{
	string ret = "";
	if (n == 0)
	{
		for (int i = 0; i < m; i++) ret.push_back('z');
		return ret;
	}
	if (m == 0)
	{
		for (int i = 0; i < n; i++) ret.push_back('a');
		return ret;
	}
	if (dp[n - 1][m] >= k)
	{
		ret = 'a' + ans(n - 1, m, k);
	}
	else
	{
		ret = 'z' + ans(n, m - 1, k - dp[n - 1][m]);
	}
	
	return ret;
}


void solve()
{
	ll n, m, k; cin >> n >> m >> k;
	for (int i =1; i <= n; i++) dp[i][0] = 1;
	for (int i = 1; i <= m; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] > inf) dp[i][j] = inf;
		}
	}
	if (dp[n][m] < k)
	{
		cout << "-1\n";
		return;
	}
	
	string ret = ans(n, m, k);
	cout << ret << "\n";
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


