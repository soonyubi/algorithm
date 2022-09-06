
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
const int inf = 1e9;
void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	int ans = inf;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != 'a') continue;
		if (i + 1 < n)
		{
			if (s[i + 1] == 'a')
			{
				ans = min(ans, 2);
			}
		}
		if (i + 2 < n)
		{
			if (s[i + 2] == 'a')
			{
				ans = min(ans, 3);
			}
		}
		if (i + 3 < n)
		{
			int cnt[3] = { 0,0,0 };
			for (int k = i; k <= i + 3; k++) cnt[s[k] - 'a']++;
			if (cnt[0] > cnt[1] && cnt[0] > cnt[2])
			{
				ans = min(ans, 4);
			}
		}
		if (i + 6 < n)
		{
			int cnt[3] = {0,0,0};
			for (int k = i; k <= i + 6; k++) cnt[s[k] - 'a']++;
			if (cnt[0] > cnt[1] && cnt[0] > cnt[2])
			{
				ans = min(ans, 7);
			}
		}
	}
	if (ans == inf) cout << "-1\n";
	else cout << ans << "\n";
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


