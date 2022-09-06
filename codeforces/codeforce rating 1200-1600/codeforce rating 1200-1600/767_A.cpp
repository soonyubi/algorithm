
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
	vector<int> cnt(n+1, 0);
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{ 
		cin >> v[i];
		cnt[v[i]]++;
	}
	int mex = 0;
	map<int, int> mp;
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		cnt[v[i]]--; mp[v[i]] = 1;
		while (mp.count(mex)) mex++;
		if (cnt[mex] == 0)
		{
			ans.push_back(mex);
			mex = 0;
			mp.clear();
		}
	}
	cout << ans.size() << "\n";
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


