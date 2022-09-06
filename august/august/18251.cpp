
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
	ll d, p, q; cin >> d >> p >> q;
	ll ret = d / (p * q) * (p * q);
	if (ret > 0) ret -= p * q;
	d -= ret;
	if (p < q) swap(p, q);
	ll temp = 2e9;
	for (ll i = 0; i * p <= d + p; i++)
	{
		temp = min(temp, i * p+ ((d - p * i + q - 1) / q) * q);
	}
	ret += temp;
	cout << ret << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


