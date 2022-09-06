
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
	ll n, k; cin >> n >> k;
	vector<ll> v;
	for (ll i = 1; i <= n; i++) v.push_back(i);
	
	if (k % 2 == 1)
	{
		cout << "YES\n";
		for (int i = 0; i < n; i += 2)
		{
			cout << v[i] << " " << v[i + 1] << "\n";
		}
		return;
	}
	for (int i = 1; i < n; i += 2)
	{
		if (v[i] % 4 == 0) continue;
		if ((v[i] + k) % 4 != 0)
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i += 2)
	{
		if (v[i + 1] % 4 == 0)
		{
			cout << v[i] << " " << v[i + 1] << "\n";
		}
		else
		{
			cout << v[i + 1] << " " << v[i] << "\n";
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


