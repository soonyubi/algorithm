
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
	ll ans = LLONG_MAX;
	for (int i = 0; i < n; i++)
	{
		ll temp_ans = 0;
		ll temp = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			ll cnt = temp / v[j] + 1;
			
			temp_ans += cnt;
			temp = cnt * v[j];
		}
		temp = 0;
		for (int j = i + 1; j < n; j++)
		{
			ll cnt = temp / v[j] + 1;
			
			temp_ans += cnt;
			temp = cnt * v[j];
		}
		
		ans = min(ans, temp_ans);
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


