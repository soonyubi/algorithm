
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

void solve()
{
	int n; cin >> n;
	vector<ll> v(n);
	ll sum = 0;
	for (ll& x : v)
	{
		cin >> x;
		sum += x;
	}
	if ((2*sum) % n != 0)
	{
		cout << 0 << "\n";
		return;
	}
	ll ans = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		ll tar = 2 * sum / n - v[i];
		auto it = lower_bound(v.begin() + i + 1, v.end(), tar);
		if (it == v.end() || *it != tar) continue;
		auto nxt = upper_bound(v.begin() + i + 1, v.end(), tar);
		ans += nxt - it;
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


