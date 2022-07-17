
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
	ll n, l, r; cin >> n >> l >> r;
	vector<ll> ans;
	
	for (int i = 1; i <= n; i++)
	{
		if (l % i == 0)
		{
			ans.push_back(l); continue;
		}

		ll left = l / i + 1;
		ll right = r / i;
		if (right >= left)
		{
			ans.push_back(left * i);
			continue;
		}
		else
		{
			cout << "NO\n";
			return;
		}
	}
	
	cout << "YES\n";
	for (auto u : ans)
	{
		cout << u << " ";
	}cout << "\n";
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


