
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
struct P
{
	int x, y, z;
};
void solve()
{
	int n; cin >> n;
	vector<ll> v(n);
	for (ll& x : v) cin >> x;
	if (v[n - 1] < v[n - 2])
	{
		cout << "-1\n";
		return;
	}
	if (v.back() >= 0)
	{
		cout << n - 2 << "\n";
		for (int i = 1; i <= n - 2; i++)
		{
			cout << i << " " << n - 1 << " " << n << "\n";
		}
	}
	else
	{
		if (is_sorted(v.begin(), v.end()))
		{
			cout <<"0\n";
		}
		else
		{
			cout << "-1\n";
		}
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


