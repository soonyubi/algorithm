
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

ll n, h;
vector<ll> v;

bool check(ll mid)
{
	ll sum = mid;
	for (int i = 0; i < n - 1; i++)
	{
		sum += min(v[i + 1] - v[i], mid);
	}
	return sum >= h;
}
void solve()
{
	cin >> n >> h;
	v = vector<ll>(n);
	for (ll& x : v) cin >> x;

	ll lo = 0, hi = 1e18, ans = hi;
	while (lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		
		if (check(mid))
		{
			hi = mid-1;
			ans = mid;
		}
		else
		{
			lo = mid+1;
		}
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


