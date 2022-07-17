
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
	ll n, c, q; cin >> n >> c >> q;
	string s; cin >> s;
	vector<ll> left(c + 1);
	vector<ll> right(c + 1);
	vector<ll> diff(c + 1);
	left[0] = 0, right[0] = n;
	for (int i = 1; i <= c; i++)
	{
		ll l, r; cin >> l >> r; l--, r--;
		left[i] = right[i - 1];
		right[i] = left[i] + (r - l + 1);
		diff[i] = left[i] - l;
	}
	while (q--)
	{
		ll k; cin >> k;
		k--;
		for (int i = c; i >= 1; i--)
		{
			if (k < left[i]) continue;
			else k -= diff[i];
		}
		cout << s[k] << "\n";
	}
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


