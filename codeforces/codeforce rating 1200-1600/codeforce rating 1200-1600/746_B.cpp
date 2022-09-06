
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
	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int& x : v) cin >> x;
	if (is_sorted(v.begin(), v.end()))
	{
		cout << "YES\n";
		return;
	}
	if (n <= 2 * x)
	{
		cout << "YES\n";
		return;
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


