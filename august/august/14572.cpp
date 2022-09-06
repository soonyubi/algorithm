
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
int cnt[33];

void solve()
{
	int n, k, d; cin >> n >> k >> d;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int sz, x; cin >> sz >> x;
		v[i].first = x;
		while (sz--)
		{
			int xx; cin >> xx; xx--;
			v[i].second |= (1 << xx);
		}
	}
	sort(v.begin(), v.end());
	int l = 0, r = 0;
	int ans = 0;
	while (r < n)
	{
		while (v[r].first - v[l].first > d)
		{
			for (int i = 0; i < 30; i++)
			{
				if (v[l].second & (1 << i)) cnt[i]--;
			}
			l++;
		}
		int temp = 0;
		for (int i = 0; i < 30; i++)
		{
			if (v[r].second & (1 << i)) cnt[i]++;
		}
		for (int i = 0; i < 30; i++)
		{
			if (cnt[i] > 0 && cnt[i] < (r - l + 1)) temp++;
		}
		ans = max(ans, temp * (r - l + 1));
		r++;
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


