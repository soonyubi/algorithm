
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
ll n;
ll dp[2][55][111];

ll go(ll flag, ll idx, ll cnt)
{
	if (idx == n) return dp[flag][idx][cnt+n] = (flag || cnt != 0);
	ll& ret = dp[flag][idx][cnt+n];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(flag, idx + 1, cnt + 1);
	ret += go(flag || cnt - 1 < 0, idx + 1, cnt - 1);
	return ret;
}
void track(ll flag, ll idx, ll cnt, ll k)
{
	if (idx == n) return;
	if (dp[flag][idx + 1][cnt + 1 + n] > k)
	{
		if (idx == n - 1 && k == 2) cout << ")";
		else cout << "(";
		track(flag, idx + 1, cnt + 1, k);
	}
	else
	{
		cout << ")";
		track(flag || cnt - 1 < 0, idx + 1, cnt - 1, k - dp[flag][idx + 1][cnt + 1 + n]);
	}
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	ll k; cin >> n >> k;
	
	if (go(0, 0, 0) <= k) cout << "-1\n";
	else
	{
		track(0, 0, 0, k);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


