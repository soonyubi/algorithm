
/*
*   Time :
*   Subject : bitmask dp
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
int n, mod;
string nums[22];
int pw[55];
int len[22];
int value[22];
ll dp[1 << 15][100];

ll go(ll bit, ll md)
{
	ll& ret = dp[bit][md];
	if (ret != -1) return ret;
	if (bit + 1 == (1 << n))
	{
		if (md) return ret = 0;
		return ret = 1;
	}
	ret = 0;

	for (int i = 0; i < n; i++)
	{
		if (bit & (1 << i)) continue;
		ll nmd = md * pw[len[i]] + value[i];
		nmd %= mod;
		ret += go(bit | (1 << i), nmd);
	}

	return ret;

}
void solve()
{
	ll all = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		all *= (i + 1);
	}
	cin >> mod;
	pw[0] = 1;
	for (int i = 1; i < 55; i++) pw[i] = pw[i - 1] * 10 % mod;
	for (int i = 0; i < n; i++)
	{
		len[i] = nums[i].size();
		reverse(nums[i].begin(), nums[i].end());
		for (int j = 0; j < nums[i].size(); j++)
		{
			value[i] += (nums[i][j] - '0') % mod * pw[j] % mod;
		}
		value[i] %= mod;
	}

	memset(dp, -1, sizeof(dp));

	ll cnt = go(0, 0);
	ll g = gcd(all, cnt);

	cout << cnt / g << "/" << all / g << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


