
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
	for (ll& x : v) cin >> x;
	reverse(v.begin(), v.end());
	ll p = 1, q = v[0];
	for (int i = 1; i < n; i++)
	{
		p += q * v[i];
		ll g = gcd(p, q);
		p /= g; q /= g;
		
		swap(p, q);
	}
	ll g = gcd(p, q);
	p /= g, q /= g;
	cout << q - p << " " << q << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


