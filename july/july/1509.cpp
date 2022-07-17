
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
int dp[2501][2501];
int dp2[2501];
string s;
const int inf = 1e9;
int isPal(int st, int ed)
{
	int& res = dp[st][ed];
	if (res != -1) return res;
	if (st >= ed) return 1;
	if (s[st] != s[ed]) return res= 0;
	
	return res = isPal(st + 1, ed - 1);
}
void solve()
{
	cin >> s; int n = s.size(); s = '#' + s;
	memset(dp, -1, sizeof(dp));
	memset(dp2, inf, sizeof(dp2));
	dp2[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp2[i] = dp2[i - 1] + 1;
		for (int j = 1; j < i; j++)
		{
			if (!isPal(j, i)) continue;
			dp2[i] = min(dp2[i], dp2[j - 1] + 1);
		}
	}
	cout << dp2[n] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


