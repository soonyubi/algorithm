
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



ll p(ll n, ll k,ll mod)
{
	if (k == 0) return 1ll;
	if (k == 1) return n;
	if (k % 2 == 1) return (n * p(n, k - 1,mod) % mod) % mod;
	ll temp = p(n, k / 2,mod) % mod;
	return (temp * temp) % mod;
}

void solve()
{
	const ll mod = 1e9 + 7;
	ll k; cin >> k;
	ll x = (p(2, k, mod - 1) - 2) % (mod - 1);
	
	ll ans = 6;
	ans = (ans * p(4, x,mod) % mod) % mod;
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


