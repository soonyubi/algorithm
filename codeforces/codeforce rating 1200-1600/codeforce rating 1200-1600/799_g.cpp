
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
	int n, k; cin >> n >> k;
	vector<ll> v(n);
	vector<bool> chk(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n - 1; i++)
	{
		if (v[i] < v[i + 1] * 2) chk[i] = true;
	}
	ll ctg = 0; ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (chk[i]) ctg++;
		else
		{
			if (ctg >= k)
			{
				ans += (ctg - (k - 1));
				
			}
			ctg = 0;
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


