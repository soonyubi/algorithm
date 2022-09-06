
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

ll dp[1001][1001]; //2 
ll dp2[1001][1001]; //5
pll cnt[1001][1001];
const ll inf = 1e9;
pll check(ll num)
{
	ll five = 0, two = 0;
	if (num == 0) return { inf,inf };
	while (num % 5 == 0)
	{
		num /= 5;
		five++;
	}
	while (num % 2 == 0)
	{
		num /= 2;
		two++;
	}
	return { two,five };
}
pll sum(pll a, pll b)
{
	return { a.first + b.first, a.second + b.second };
}

void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ll x; cin >> x;
			cnt[i][j] = check(x);
			dp[i][j] = inf;
			dp2[i][j] = inf;
		}
	}
	
	dp[0][0] = cnt[0][0].first;
	dp2[0][0] = cnt[0][0].second;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0) continue;
			ll temp = inf;
			if (i - 1 >= 0) temp = min(temp,dp[i - 1][j]);
			if (j - 1 >= 0) temp = min(temp, dp[i][j - 1]);

			dp[i][j] = min(temp + cnt[i][j].first, dp[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0) continue;
			ll temp = inf;
			if (i - 1 >= 0) temp = min(temp, dp2[i - 1][j]);
			if (j - 1 >= 0) temp = min(temp, dp2[i][j - 1]);

			dp2[i][j] = min(temp + cnt[i][j].second, dp2[i][j]);
		}
	}
	
	cout << min(dp[n - 1][n - 1], dp2[n - 1][n - 1]) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


