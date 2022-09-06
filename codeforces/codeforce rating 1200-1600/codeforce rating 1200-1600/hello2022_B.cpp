
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
void solve()
{
	const int INF = 1e9 + 7;
	int n; cin >> n;
	int L = INF, lc = INF, R = -INF, rc = INF, D = 0, dc = INF;
	for (int i = 0; i < n; i++)
	{
		int l, r, c; cin >> l >> r >> c;
		if (D < r - l + 1)
		{
			D = r - l + 1;
			dc = c;
		}
		if (D == r - l + 1)
		{
			dc = min(dc, c);
		}
		if (L == l && lc > c)
		{
			lc = c;
		}
		if (L > l)
		{
			L = l;
			lc = c;
		}
		if (R == r && rc > c)
		{
			rc = c;
		}
		if (R < r)
		{
			R = r;
			rc = c;
		}
		if (D == R - L + 1) cout << min(dc, lc + rc) << "\n";
		else cout << lc + rc << "\n";
	}
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


