
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int dy[] = { 0,-1,0,1,0 };
int dx[] = { 0,0,-1,0,1 };// 위 왼 --> 1,2 // 아래 우 --> 3,4 
int r, c, m; 
struct e
{
	int s, d, z;
	bool exist;
};
e board[111][111];
e tmp[111][111];
int ans;

void go(int n)
{
	if (n == c+1) return;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) tmp[i][j] = { 0,0,0,false };
	for (int i = 1; i <= r; i++)
	{
		if (board[i][n].exist)
		{
			ans += board[i][n].z;
			board[i][n] = { 0,0,0,false };
			break;
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (board[i][j].exist)
			{
				int ny, nx, nd, ns = board[i][j].s, nz=board[i][j].z;
				if (board[i][j].d <= 2)
				{
					// 현재 방향이 왼쪽, 또는 위쪽
					board[i][j].s * dy[board[i][j].d]
				}
				else
				{
					// 현재 방향이 오른쪽 또는 아래쪽
				}
			}
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			board[i][j] = tmp[i][j];
		}
	}
}
void solve()
{
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++)
	{
		int y, x, s, d, z; cin >> y >> x >> s >> d >> z;
		// 위 왼 --> 1,2 // 아래 우 --> 3,4
		if (d == 1) board[y][x] = { s,1,z };
		else if (d == 4) board[y][x] = { s,2,z };
		// 아래 우 --> 3,4
		else if (d == 2) board[y][x] = { s,3,z };
		else if (d == 3) board[y][x] = { s,4,z };
	}

	go(1);
	cout << ans << "\n";
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


