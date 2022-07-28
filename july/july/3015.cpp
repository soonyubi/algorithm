
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
	vector<pll> stk;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll cnt = 1;
		while (!stk.empty() && stk.back().first <= v[i])
		{
			if (stk.back().first == v[i])
			{
				ans += stk.back().second;
				cnt = stk.back().second + 1;
				stk.pop_back();
			}
			else
			{
				ans += stk.back().second;
				stk.pop_back();
				cnt = 1;
			}
		}
		if (!stk.empty()) ans++;
		stk.push_back({ v[i],cnt });
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


