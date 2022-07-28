
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
map<int, int> mp;

void solve()
{
	mp.clear();
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		mp[x] ++;
	}
	
	int cnt1 = 0; int cnt2 = 0;
	for (auto u : mp)
	{
		if (u.second == 1)
		{
			cnt1++;
		}
		else
		{
			cnt2++;
		}
	}
	cout << cnt2 + (cnt1 + 1) / 2 << "\n";
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


