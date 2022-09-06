
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
vector<pii> v;
int dp[111][111];
int dfs(int st, int ed)
{
	int& ret = dp[st][ed];
	if (ret != -1) return ret;
	ret = 0;
	for (auto& u : v)
	{
		if (u.first < st || ed < u.second) continue;
		ret = max(ret, dfs(st, u.first - 1) + dfs(u.first + 1, u.second - 1) + dfs(u.second + 1, ed) + 1);
	}
	return ret;
}
void solve()
{
	int n; cin >> n;
	memset(dp, -1, sizeof(dp));
	v.resize(n);
	for (auto& x : v)
	{
		cin >> x.first >> x.second;
		if (x.first > x.second)swap(x.first, x.second);
	}
	cout << dfs(1, 100) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


