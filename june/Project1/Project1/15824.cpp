
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
const ll MOD = 1e9 + 7;
ll p(ll a, ll b)
{
	ll ret = 1ll;
	while (b)
	{
		if (b & 1) ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}
void solve()
{
	ll n; cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll mx = p(2, i);
		ll mn = p(2, n - i - 1);
		ans += (v[i] % MOD) * mx % MOD;
		ans -= (v[i] % MOD) * mn % MOD;
		ans = ((ans % MOD) + MOD) % MOD;
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


