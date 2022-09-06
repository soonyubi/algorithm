
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
ll dp[55][55];

ll go(ll i, ll j)
{
	if (i == n)
	{
		if (j == 0) return 1;
		else return 0;
	}
	if (i < j) return 0;
	ll& ret = dp[i][j];
	if (ret != -1) return ret;

	ret = 0;

	ret += go(i + 1, j + 1);
	if(j-1>=0) ret += go(i + 1, j - 1);

	return ret;
}
void track(ll i, ll j, ll k)
{

	if (i == n) return;
	if (dp[i + 1][j + 1] > k)
	{
		cout << "(";
		track(i + 1, j + 1, k);
	}
	else
	{
		cout << ")";
		track(i + 1, j - 1, k - dp[i + 1][j + 1]);
	}
}
void solve()
{
	ll k;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));

	if (go(0, 0) <= k) cout << "-1\n";
	else
	{
		track(0, 0, k);
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


