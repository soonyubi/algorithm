
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
	ll n, s; cin >> n >> s;
	vector<ll> v1, v2;
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		if (i < (n / 2)) v1.push_back(x);
		else v2.push_back(x);
	}
	ll sz1 = v1.size();
	ll sz2 = v2.size();
	vector<ll> psum1, psum2;

	for (int i = 1; i < (1 << sz1); i++)
	{
		ll tmp_sum = 0;
		for (int j = 0; j < sz1; j++)
		{
			if (i & (1 << j)) tmp_sum += v1[j];
		}
		psum1.push_back(tmp_sum);
	}
	for (int i = 1; i < (1 << sz2); i++)
	{
		ll tmp_sum = 0;
		for (int j = 0; j < sz2; j++)
		{
			if (i & (1 << j)) tmp_sum += v2[j];
		}
		psum2.push_back(tmp_sum);
	}
	sort(psum1.begin(), psum1.end());
	sort(psum2.begin(), psum2.end());
	ll ans = 0;
	for (auto u : psum1) if (u == s) ans++;
	for (auto u : psum2) if (u == s) ans++;
	
	for (int i = 0; i < psum1.size(); i++)
	{
		ll tar = s - psum1[i];
		ans += upper_bound(psum2.begin(), psum2.end(), tar) - lower_bound(psum2.begin(), psum2.end(), tar);
		
	}
	cout << ans << "\n";
}
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


