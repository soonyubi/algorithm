
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
	int n, s; cin >> n >> s;
	int sum = 0;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x == 1)
		{
			sum++;
			v.push_back({ sum,i });
		}
	}
	if (sum < s)
	{
		cout << "-1\n";
		return;
	}
	else if (sum == s)
	{
		cout << "0\n";
		return;
	}
	//for (auto u : v) cout << u.first << " " << u.second << "\n";
	int ans = 1e9;
	for (int i = 0; i < v.size(); i++)
	{
		if (i + s + 1 < v.size())
		{
			int left = v[i].second + 1;
			int right = n - v[i + s + 1].second;
			ans = min(ans, left + right);
			
		}
	}
	if (s < v.size()) ans = min(ans, n - v[s].second);
	if (v.size() - s - 1 >= 0) ans = min(ans, v[v.size() - s - 1].second + 1);
	
	cout << ans << "\n";
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


