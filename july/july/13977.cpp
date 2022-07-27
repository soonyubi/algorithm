
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
const ll maxn = 4000001;
const ll mod = 1e9 + 7;
ll fact[maxn];
ll power(ll x, ll k)
{
	if (k == 0) return 1;
	if (k == 1) return x;
	else if (k % 2 == 1) return (x * power(x, k - 1))%mod;
	ll tmp = power(x, k / 2)%mod;
	return (tmp * tmp)%mod;
}
void solve()
{
	fact[0] = 1;
	for (ll i = 1; i <= maxn; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int n, k; cin >> n >> k;
		
		ll a = fact[n];
		ll b = (fact[n - k] * fact[k]) % mod;
		b = power(b, mod - 2);

		ll ret = (a * b) % mod;
		cout << ret << "\n";
	}
	
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
