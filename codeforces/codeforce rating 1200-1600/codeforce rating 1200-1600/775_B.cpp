
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
	ll mx = 0,sum=0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		mx = max(mx, v[i]);
	}
	if (mx == sum)
	{
		cout << 0 << "\n";
		return;
	}
	if (mx * 2 <= sum)
	{
		cout << "1\n";
	}
	else
	{
		cout << mx*2 - sum << "\n";
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


