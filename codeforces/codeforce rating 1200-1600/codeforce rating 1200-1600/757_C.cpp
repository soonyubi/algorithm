
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

const ll mod = 1e9 + 7;

ll p(ll a, ll k)
{
	if (k == 0) return 1;
	if (k == 1) return a%mod;
	if (k % 2 == 1) return a * p(a, k - 1) % mod;
	ll temp = p(a, k / 2) % mod;
	return temp * temp % mod;
}

void solve()
{
	ll n, m; cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < m; i++)
	{
		ll l, r, c; cin >> l >> r >> c;
		sum |= c;
	}
	ll ans = (p(2, n - 1) % mod * sum % mod) % mod;
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


