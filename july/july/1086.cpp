
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

int n, mod;
string nums[16];
ll pw[51];
ll dp[1 << 16][101];
ll len[16];
ll value[16];

ll go(ll bit, ll md)
{
	ll& ret = dp[bit][md];
	if (ret != -1) return ret;
	if (bit == (1 << n) - 1)
	{
		return ret = (md == 0 ? 1 : 0);
	}
	ret = 0;

	for (int i = 0; i < n; i++)
	{
		if ((1 << i) & bit) continue;
		ll nmd = md * pw[len[i]] + value[i];
		nmd %= mod;
		ret += go((1 << i) | bit, mod);
	}
	return ret;
}
void solve()
{
	int n; cin >> n;
	ll all = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		len[i] = nums[i].size();
		all *= (i + 1);
	}
	cin >> mod;
	pw[0] = 1;
	for (int i = 1; i < 51; i++)
	{
		pw[i] = (pw[i - 1] * 10) % mod;
	}
	for (int i = 0; i < n; i++)
	{
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
	cout << cnt / g << " " << all / g << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


