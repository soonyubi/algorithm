
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

int n; 
int w[20][20];
int dp[20][1 << 20];
const int inf = 1e9;
int dfs(int cur, int path)
{
	path |= (1 << cur);
	if (path == (1 << n) - 1)
	{
		if (w[cur][0] > 0)
		{
			return w[cur][0];
		}
		return inf;
	}

	int& ret = dp[cur][path];
	if (ret != -1) return ret;
	ret = inf;

	for (int i = 0; i < n; i++)
	{
		if (i != cur && (path & (1 << i)) == 0 && w[cur][i] > 0)
		{
			ret = min(ret, dfs(i, path) + w[cur][i]);
		}
	}
	return ret;
}
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


