
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
const ll mod = 1e4 + 7;
ll fact[1001];
ll inv(ll a, ll b) // a^-1 mod b 
{
	ll x1 = 1, x2 = 0;
	ll y1 = 0, y2 = 1;
	ll r1 = a * x1, r2 = b * y2;
	while (true)
	{
		//cout << x1 << " " << y1 << " " << r1 << "\n";
		//cout << x2 << " " << y2 << " " << r2 << "\n";
		//cout << "-----------------------------------\n";
		ll q = r1 / r2;
		ll temp_x = x1;
		ll temp_y = y1;
		ll temp_r = r1;
		x1 = x2;
		y1 = y2;
		x2 = (temp_x - x2 * q%mod)%mod;
		y2 = (temp_y - y2 * q%mod)%mod;
		r1 = r2;
		r2 = temp_r % r2;
		if (r2 == 0)
		{
			break;
		}
	}
	return x1%mod;
}
void solve()
{
	ll n, k; cin >> n >> k;
	if (k == 0)
	{
		cout << "1\n";
		return;
	}
	fact[0] = 1;
	fact[1] = 1;
	for (ll i = 2; i <= n; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
	}
	ll x = inv(fact[n - k]*fact[k]%mod,mod)%mod;
	ll ans = fact[n]%mod;
	ans *= x; ans %= mod;
	while (ans < 0) ans += mod;
	cout << ans%mod << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


