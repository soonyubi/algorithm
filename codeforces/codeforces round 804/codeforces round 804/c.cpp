
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
const int MOD = 1e9 + 7;

void solve()
{
	int n; cin >> n;
	vector<int> v(n);
	vector<int> p(n);
	for (int i = 0; i < n; i ++ )
	{
		cin >> v[i];
		p[v[i]] = i;
	}

	int l, r;
	l = r = p[0];
	ll ans = 1;

	for (int i = 1; i < n; i++)
	{
		if (p[i] < l) l = p[i];
		else if (p[i] > r) r = p[i];
		else ans = ans * (r - l + 1 - i) % MOD;
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


