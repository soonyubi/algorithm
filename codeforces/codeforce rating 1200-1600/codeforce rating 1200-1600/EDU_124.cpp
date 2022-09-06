
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
const ll inf = LLONG_MAX;
void solve()
{
	int n; cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	for (ll& x : a) cin >> x;
	for (ll& x : b) cin >> x;

	// 선2개
	ll ans = inf;
	ans = min(ans, abs(a[0]-b[0]) + abs(a[n - 1]-b[n - 1]));
	ans = min(ans, abs(a[0]-b[n-1]) + abs(a[n - 1]-b[0]));

	// 선3개
	ll mn1 = inf, mn2 = inf, mn3 = inf, mn4 =inf;
	for (int i = 0; i < n ; i++)
	{
		mn1 = min(mn1, abs(a[0] - b[i])); // a0
		mn2 = min(mn2, abs(a[n-1] - b[i])); // a_n
		mn3 = min(mn3, abs(a[i] - b[0])); // b0
		mn4 = min(mn4, abs(a[i] - b[n-1])); //bn
	}
	// 1. a_n - b_n
	ans = min(ans, abs(a[n - 1] - b[n - 1]) + mn1 + mn3);
	// 2. a_n -b_1
	ans = min(ans, abs(a[n - 1] - b[0]) + mn1 + mn4);
	//3. a_0_b_0
	ans = min(ans, abs(a[0] - b[0]) + mn2 + mn4);
	//4 a_0 - b_n
	ans = min(ans, abs(a[0] - b[n-1]) + mn2 + mn3);

	ans = min(ans, mn1 + mn2 + mn3 + mn4);

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


