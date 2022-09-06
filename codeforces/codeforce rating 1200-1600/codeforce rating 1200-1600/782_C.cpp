
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
	ll n, a, b; cin >> n >> a >> b;
	vector<ll> v(n+1);
	vector<ll> psum(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	partial_sum(v.begin(), v.end(), psum.begin());
	ll ans = LLONG_MAX;
	for (int i = 0; i <= n; i++)
	{
		ans = min(ans, (a + b) * (v[i] - v[0]) + b*(psum[n]-psum[i] - (n-i)*v[i]));
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


