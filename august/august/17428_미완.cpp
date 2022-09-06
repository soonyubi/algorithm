
/*
*   Time :
*   Subject :
*1
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<int, int>
#define pll pair<ll, ll>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
ll n, k;
ll dp[55][55];
ll go(ll a, ll b)
{
	if (b < 0)return 0;
	if (a == n) return !b;
	ll& ret = dp[a][b];
	if (ret != -1) return ret;
	return ret = go(a + 1, b + 1) + go(a + 1, b - 1);
}
void tr(ll a, ll b, ll k)
{

}
void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	
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


