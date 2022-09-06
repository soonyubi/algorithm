
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
int board[101][101];
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c; cin >> c;
			board[i][j] = c - '0';
		}
	}
	vector<pair<pii,pii>> ans;
	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			if (board[i][j] == 1)
			{
				if (i - 1 >= 1 )
				{
					ans.push_back({ {i-1,j},{i,j} });
				}
				else if (j - 1 >= 1)
				{
					ans.push_back({ {i,j-1},{i,j} });
				}
				else
				{
					cout << "-1\n";
					return;
				}
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto u : ans)
	{
		cout << u.first.first << " " << u.first.second << " " << u.second.first << " " << u.second.second << "\n";
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


