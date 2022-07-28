
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
const ll maxn = 1e7 + 1;
bool check[maxn];
vector<ll> prime;
void solve()
{
	ll a, b; cin >> a >> b;
	for (ll i = 2; i < maxn; i++)
	{
		if (check[i]) continue;
		prime.push_back(i);
		for (ll j = 2 * i; j < maxn; j += i) check[j] = true;
	}

	
	ll ans = 0;
	for (auto p : prime)
	{
		ll cur = p;
		ll temp = cur;
		while (temp<=b/cur)
		{
			temp *= cur;
			if (temp >= a) ans++;
		}
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


