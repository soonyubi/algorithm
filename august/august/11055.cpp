
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
void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		dp[i] = v[i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + v[i]);
			}
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) mx = max(mx, dp[i]);
	cout << mx << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


