
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
	ll n, k; cin >> n >> k;
	vector<ll> v(n);
	ll ans = 0;
	for (ll& x : v)
	{
		cin >> x;
		ans += x / k;
		x %= k;
	}
	int i = 0, j = n - 1;
	sort(v.begin(), v.end());
	while (i < j)
	{
		if (v[i] + v[j] >= k)
		{
			ans++;
			i++, j--;
		}
		else
		{
			i++;
		}
		if (i == j) break;
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


