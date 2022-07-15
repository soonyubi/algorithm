
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
const ll inf = 1e9;
void solve()
{
	ll n, c; cin >> n >> c;
	vector<ll> v1, v2;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (i < n / 2) v1.push_back(x);
		else v2.push_back(x);
	}
	ll a = v1.size();
	ll b = v2.size();
	vector<ll> psum1, psum2;
	for (ll i = 0; i < (1ll << a); i++)
	{
		ll sum = 0;
		for (ll j = 0; j < a; j++)
		{
			if (i & (1ll << j)) sum += v1[j];
		}
		if (sum <= c) psum1.push_back(sum);
	}
	for (ll i = 0; i < (1ll << b); i++)
	{
		ll sum = 0;
		for (ll j = 0; j < b; j++)
		{
			if (i & (1ll << j)) sum += v2[j];
		}
		if (sum <= c) psum2.push_back(sum);
	}

	sort(psum2.begin(), psum2.end());
	ll ans = 0;
	for (int i = 0; i < psum1.size(); i++)
	{
		ll x = c - psum1[i];
		if (c < 0) continue;
		ll cnt = upper_bound(psum2.begin(), psum2.end(), x) - psum2.begin();
		ans += cnt;
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


