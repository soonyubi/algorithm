
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
int dp[100001];
const int inf = 1e9;
void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)dp[i] = inf;
	
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		
		for (int j = 1; j <= sqrt(i); j++)
		{
			dp[i] = min(dp[i - j * j] + 1,dp[i]);
		}
	}

	cout << dp[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 solve();
	return 0;
}


