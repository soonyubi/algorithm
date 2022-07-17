
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
void solve()
{
	ll n; cin >> n;
	vector<ll>v(n);
	for (ll& x : v) cin >> x;
	ll idx = -1;
	for (ll i = 0; i < n-1; i++)
	{
		if (v[i] == 0) continue;
		idx = i; break;
	}
	if (idx == -1)
	{
		cout << "0\n";
		return;
	}
	ll ans = 0;
	for (ll i = idx; i < n - 1; i++)
	{
		if (v[i] == 0) ans++;
		else ans += v[i];
	}
	cout << ans << "\n";

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


