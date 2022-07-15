/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<ll, ll>
#define pll pair<ll, ll>
// ll_MAX ll_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
ll xx[200001];
ll n, m;
const ll inf = 200000;
vector<ll> v;
bool check(ll mid)
{
	ll rest = 0;
	for (ll i = 1; i <= n; i++)
	{
		if (xx[i] > mid)
		{
			rest += xx[i] - mid;
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		if (mid - xx[i] > 0)
		{
			rest -= (mid - xx[i]) / 2;
		}
	}
	return rest <= 0;


}
void solve()
{
	cin >> n >> m;
	v = vector<ll>(m + 1);
	for (ll i = 1; i <= m; i++)
	{
		cin >> v[i];
		xx[v[i]]++;
	}

	ll lo = 0, hi = 2 * inf; ll ans = hi;
	while (lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if (check(mid))
		{
			ans = min(ans, mid);
			hi = mid - 1;

		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << ans << "\n";
	for (ll i = 1; i <= n; i++) xx[i] = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t; cin >> t;
	while (t--) solve();
	return 0;
}