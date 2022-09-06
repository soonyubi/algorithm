
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

string str;
int dp[1111][1111];
const int mod = 10007;

int go(int s, int e)
{
	if (s > e) return 0;
	if (s == e) return 1;

	int& ret = dp[s][e];
	if (ret != -1) return ret%mod;

	
	ret = (go(s, e - 1) + go(s + 1, e)) % mod;
	ret -= go(s + 1, e - 1);
	if (ret < 0) ret += mod;

	if (str[s] == str[e])
	{
		ret += (go(s + 1, e - 1) + 1)%mod;
	}
	return ret % mod;
}

void solve()
{
	cin >> str;
	int n = str.size();
	str = "#" + str;

	memset(dp, -1, sizeof(dp));
	cout << go(1, n) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


