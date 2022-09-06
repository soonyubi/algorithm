
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
	int n; cin >> n;
	vector<pii> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		v[i] = { x,i };
	}
	stack<pair<pii, int>> stk;
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (stk.empty())
		{
			stk.push({ { v[i].first,v[i].first }, v[i].second });
			continue;
		}
		int mn = v[i].first;
		int mx = v[i].first;

		while (!stk.empty()&&(stk.top().first.first -1 == mx || stk.top().first.second +1 == mn))
		{
			ans.push_back(stk.top().second);
			mn = min(mn, stk.top().first.first);
			mx = max(mx, stk.top().first.second);
			stk.pop();
		}
		stk.push({ {mn,mx},v[i].second });
	}
	
	for (auto u : ans) cout << u << "\n";

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


