
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

bool cmp(pair<pll, ll> a, pair<pll, ll> b)
{
	return a.first.first < b.first.first;
}
void solve()
{
	int n, m; cin >> n >> m;
	vector<pair<pll,ll>> v(m);
	
	for(ll i=0;i<m;i++)
	{
		ll a, b; cin >> a >> b;
		v[i].first.first = b;
		v[i].first.second = a;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end(),cmp);
	ll sum = 0;
	vector<pll> ans(n);
	for (int i = 0; i <  n; i++)
	{
		sum += v[i].first.first;
		ans[i].first = v[i].second;
	}
	for (int i = 2 * n - 1; i >= n; i--)
	{
		sum += v[i].first.first;
		ans[2 * n - 1 - i].second = v[i].second;
	}
	cout << sum << "\n";
	for (auto u : ans)
	{
		cout << u.first << " " << u.second << "\n";
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


