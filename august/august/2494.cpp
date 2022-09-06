
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
int dp[11111][11];
pii from[11111][11];
const int inf = 1e9 + 7;
void solve()
{
	memset(dp, inf, sizeof(dp));
	int n; cin >> n;
	string a, b; cin >> a >> b;
	a = '#' + a; b = '#' + b;
	

	for (int i = 0; i < 10; i++) dp[0][i] = i;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int lcnt = (b[i] - a[i] - j + 20) % 10;
			int rcnt = 10 - lcnt;

			if (dp[i][j] > dp[i - 1][j] + rcnt)
			{
				from[i][j] = { j,-rcnt };
				dp[i][j] = dp[i - 1][j] + rcnt;
			}
			if (dp[i][(j+lcnt)%10] > dp[i-1][j]+lcnt)
			{
				from[i][(j + lcnt) % 10] = { j,lcnt };
				dp[i][(j + lcnt) % 10] = dp[i - 1][j] + lcnt;
			}
		}
	}
	int ans = inf; 
	int idx = -1;
	for (int i = 0; i < 10; i++) {
		if (ans > dp[n][i])
		{
			idx = i;
			ans = dp[n][i];
		}
	}
	
	cout << ans << "\n";
	vector<pii> path;

	

	for(int i=n;i>=1;i--)
	{
		path.push_back({ i,from[i][idx].second });
		idx = from[i][idx].first;
	}
	reverse(path.begin(), path.end());
	for (auto u : path)
		cout << u.first << " " << u.second << "\n";
	

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


