
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
	int n, k; cin >> n >> k; k++;
	vector<ll> v(n);
	for (ll& x : v)
	{
		cin >> x;
		x = pow(10ll, x);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll cnt = k;
		if (i + 1 < n) cnt = min(cnt, v[i + 1] / v[i] - 1);
		ans += 1ll * v[i] * cnt;
		k -= cnt;
	}
	cout << ans << "\n";
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


