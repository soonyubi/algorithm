
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
char board[55][55];
int n, m;
bool cmp(pii a, pii b)
{
	return a.first > b.first;
}
bool isRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	return false;
}
void solve()
{
	cin >> n >> m;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == '*') v.push_back({ i,j });
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (auto u : v)
	{
		
		board[u.first][u.second] = '.';
		int ny = u.first;
		int nx = u.second;
		while (isRange(ny+1, nx) && board[ny+1][nx]=='.')
		{
			ny++;
		}
		board[ny][nx] = '*';
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j];
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


