
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
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		mp[x]++;
	}
	vector<pii> v;
	for (auto u : mp)
	{
		v.push_back(u);
	}
	
	int l = 0, r = 0;
	int mx = 0;
	int ans1 = -1, ans2 = -1;

	while (l <= r && l < v.size() && r < v.size())
	{
		if ((v[r].first == v[l].first + (r - l)))
		{
			if (v[r].second >= k)
			{
				if (mx < r - l + 1)
				{
					mx = r - l + 1;
					ans1 = v[l].first, ans2 = v[r].first;
				}
				r++;
			}
			else
			{
				r++;
				l = r;
			}
		}
		else
		{
			l = r;
		}
	}
	if (ans1 == -1)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans1 << " " << ans2 << "\n";
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


