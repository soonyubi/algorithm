
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
	int n, m; cin >> n >> m;
	vector<vector<int>> arr1 = { {1,0},{0,1} };
	vector<vector<int>> arr2 = { { 0,1 }, { 1,0 } };
	vector<vector<int>> ans(n, vector<int>(m, 0));
	for (int i = 0; i < n; i+=2)
	{
		for (int j = 0; j < m; j += 2)
		{
			if ((i + j) % 4 == 0)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int l = 0; l < 2; l++)
					{
						ans[i + k][j + l] = arr1[k][l];
					}
				}
			}
			else
			{
				for (int k = 0; k < 2; k++)
				{
					for (int l = 0; l < 2; l++)
					{
						ans[i + k][j + l] = arr2[k][l];
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << " ";
		}cout << "\n";
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


