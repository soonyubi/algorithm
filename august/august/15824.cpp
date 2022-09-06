
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
	ll ret = 1ll;
	while (k)
	{
		if (k % 2 == 1) ret = ret * a %mod;
		k /= 2;
		a = a * a % mod;
	}
	return ret;
}
void solve()
{
	ll n; cin >> n;
	vector<ll> v(n);
	for (ll& x : v) cin >> x;
	sort(v.begin(), v.end());
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll mx_cnt = p(2, i)%mod;
		ll mn_cnt = p(2, n - i - 1)%mod;
		ans += (v[i] * mx_cnt) % mod;
		ans -= (v[i] * mn_cnt) % mod;
		ans = ((ans % mod) + mod) % mod;
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


