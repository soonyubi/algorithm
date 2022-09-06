
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
string s; 
vector<string> v;
int dp[111];

int go(int idx)
{
	if(idx == s.size()) return 1;
	int& ret = dp[idx];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (idx + v[i].size() > s.size()) continue;
		bool flag = true;
		for (int j = 0; j < v[i].size(); j++)
		{
			if (s[idx + j] != v[i][j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ret |= go(idx + v[i].size());
		}
	}
	return ret;
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> s;
	int n; cin >> n;
	v.resize(n);
	for (auto& x : v) cin >> x;
	cout << go(0) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


