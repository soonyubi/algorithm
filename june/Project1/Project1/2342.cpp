
/*
*   Time :
*   Subject : DP
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int dp[100001][5][5];
const int inf = 1e9;

void solve()
{
	vector<int> v; v.push_back(0);
	int x; 
	while (cin >> x)
	{
		if (x == 0) break;
		v.push_back(x);
	}
	int n = v.size();
	for (int i = 0; i < 100001; i++) for (int j = 0; j < 5; j++) for (int k = 0; k < 5; k++) dp[i][j][k] = inf;
	dp[0][0][0] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (dp[i - 1][j][k] != inf)
				{
					if (j == v[i])
					{
						dp[i][v[i]][k] = min(dp[i][v[i]][k], dp[i - 1][j][k] + 1);
					}
				}
			}
		}
	}
}
int main()
{
	solve();
	return 0;
}


