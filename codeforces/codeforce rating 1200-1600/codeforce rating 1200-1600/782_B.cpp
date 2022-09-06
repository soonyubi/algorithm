
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
	int kk = k;
	bool flag = false;
	string s; cin >> s;
	vector<int> ans(n, 0);
	int idx = 0;
	if (k > 0)
	{
		for (int i = 0; i < n - 1; i++)
		{
			idx = i;
			if (flag) {
				s[i] = (s[i] == '0' ? '1' : '0');
			}
			if (s[i] == '0')
			{
				s[i] = '1';
				if (k % 2 == 1)
				{
					ans[i] = 0;
					continue;
				}
				else
				{
					ans[i] = 1;
					k--;

					flag = (flag ? false : true);
				}
			}
			else
			{
				if (k % 2 == 1)
				{
					ans[i] = 1;
					k--;
					flag = (flag ? false : true);
				}
				else
				{
					ans[i] = 0;
					continue;
				}
			}
			if (k <= 0) break;
		}
	}
	if (idx < n - 2)
	{
		for (int i = idx + 1; i < n; i++)
		{
			if (flag) s[i] = (s[i] == '0' ? '1' : '0');
		}
		cout << s << "\n";
		for (auto u : ans) cout << u << " "; cout << "\n";
		return;
	}
	ans[n - 1] = k;
	if ((kk - k) % 2 == 1)
	{
		if (s[n - 1] == '1') s[n - 1] = '0';
		else s[n - 1] = '1';
	}
	cout << s << "\n";
	for (auto u : ans) cout << u << " "; cout << "\n";
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


