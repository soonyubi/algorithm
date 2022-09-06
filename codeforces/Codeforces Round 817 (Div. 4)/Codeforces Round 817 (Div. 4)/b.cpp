
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
char board[2][111];
void solve()
{
	int n; cin >> n;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (board[0][i] == board[1][i]) continue;
		if (board[0][i] == 'G' && board[1][i] == 'B') continue;
		if (board[0][i] == 'B' && board[1][i] == 'G') continue;
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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


