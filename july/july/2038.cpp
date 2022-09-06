
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
int dp[11111111];
void solve()
{
	int n; cin >> n;
	dp[1] = 1;
	int idx = 1;
	int now = 1;
	while (now < n)
	{
		idx++;
		dp[idx] = 1 + dp[idx - dp[dp[idx - 1]]];
		now += dp[idx];
	}
	cout << idx << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


