
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
vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}vector<int> kmp(string s, string p)
{
	vector<int> ans;	auto pi = getPi(p);

	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		// mismatch
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		// match
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else
			{
				j++;
			}
		}
	}
	return ans;
}
bool cmp(pair<int, pii> a, pair<int, pii> b)
{
	return a.second.first < b.second.first;
}
void solve()
{
	string S; cin >> S;
	int n; cin >> n;
	vector<pair<int,pii>> cover;
	for (int i = 0; i < n; i++)
	{
		string p; cin >> p;
		vector<int> res = kmp(S, p);
		for (auto u : res)
		{
			cover.push_back({ i+1,{ u, u + p.size() - 1 } });
		}
	}
	sort(cover.begin(), cover.end(),cmp);
	vector< pair<int, pii>> ans;
	vector<bool> chk(S.size(), false);
	for (int i = 0; i < cover.size(); i++)
	{
		if (ans.empty()) ans.push_back(cover[i]);
		else
		{
			pair<int, pii> tar = { 0,{ans.back().second.second,0} };
			auto it = lower_bound(cover.begin() + i + 1, cover.end(), tar) - cover.begin();
			if (it >= i)
			{
				ans.push_back(cover[i]);
			}
			else
			{
				ans.push_back(cover[it]);
				i = it;
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto u : ans)
	{
		cout << u.first << " " << u.second.first+1 << "\n";
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


