
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
const int maxn = 200001;

void solve()
{
	ll n, k; cin >> n >> k;
	vector<ll> v(n);
	vector<ll> psum(33, 0);
	vector<vector<int>> table(33, vector<int>(n + 1, 0));
	for (ll& x : v) cin >> x;
	for (int i = 0; i < n; i++)
	{
		for (ll j = 0; j <= 30; j++)
		{
			if (v[i] & (1ll << j)) {
				
				table[j][i] = 1;
				psum[j] ++;
			}
		}
	}
	ll ans = 0;
	for (ll i = 30; i >= 0; i--)
	{
		if (n-psum[i] <= k)
		{
			k -= (n - psum[i]);
			ans += (1ll << i);
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


