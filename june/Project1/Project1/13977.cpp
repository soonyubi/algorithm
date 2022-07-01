
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int MAX = 4000000;
const ll MOD = 1000000007;
ll fact[MAX + 1];

ll pow(ll a, ll b) // a^b
{
	if (b == 1) return a;
	else if (b % 2 == 1) return (a * pow(a, b - 1)) % MOD;
	ll k = pow(a, b / 2) % MOD;
	return (k * k) % MOD;
}

void solve()
{
	fact[0] = 1;
	for (int i = 1; i <= MAX; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll n, k; cin >> n >> k;
		ll ans = fact[n];
		ll inv = pow((fact[n - k] * fact[k]) % MOD, MOD - 2);
		cout << (ans * inv) % MOD << "\n";
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


