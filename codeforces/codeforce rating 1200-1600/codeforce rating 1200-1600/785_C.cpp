
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

const int maxn = 40001; const int m = 500; const int mod = 1e9 + 7;
int dp[maxn][m];
vector<int> pal;
void getPalindrome()
{
	for (int i = 1; i < maxn; i++)
	{
		bool flag = true;
		string temp = to_string(i);
		for (int j = 0; j < temp.size() / 2; j++)
		{
			if (temp[j] != temp[temp.size() - 1 - j]) flag = false;
		}
		if (flag) pal.push_back(i);
	}
	
}
void go()
{
	for (int i = 0; i < m; i++) dp[0][i] = 1;

	for (int i=1;i<maxn;i++)
	{
		dp[i][0] = 0;
		for (int j = 1; j < pal.size(); j++)
		{
			if (i - pal[j] >= 0)
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - pal[j]][j]) % mod;
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
}
void solve()
{
	int n; cin >> n;
	cout << dp[n][m-1] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getPalindrome();
	go();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


