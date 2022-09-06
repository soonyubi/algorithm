
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

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
bool isRange(int y, int x,int n)
{
	if (y >= 1 && y <= n && x >= 1 && x <= n) return true;
	return false;
}
void solve()
{
	int n, k, r, c; cin >> n >> k >> r >> c;

	vector<vector<char>> board(n + 1, vector<char>(n + 1));
	vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));
	vector<bool> row(n + 1, false);
	vector<bool> col(n + 1, false);

	queue<pii> q;
	q.push({ r,c });
	board[r][c] = 'X';

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		row[y] = true;
		col[x] = true;

		for (int i = 0; i < 4; i++)
		{
			int ny = k * dy[i] + y;
			int nx = k * dx[i] + x;
			if (isRange(ny,nx,n))
			{
				if (!visited[ny][nx])
				{
					visited[ny][nx] = true;
					board[ny][nx] = 'X';
					q.push({ ny,nx });
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (row[i]) continue;
		int cc = -1; int rr = i;
		for (int j = 1; j <= k; j++)
		{
			if (!col[j]) { cc = j; break; }
		}
		if (cc == -1) continue;
		q.push({ rr,cc });
		board[rr][cc] = 'X';
		visited[rr][cc] = true;
		col[cc] = true;
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		row[y] = true;
		col[x] = true;

		for (int i = 0; i < 4; i++)
		{
			int ny = k * dy[i] + y;
			int nx = k * dx[i] + x;
			if (isRange(ny, nx, n))
			{
				if (!visited[ny][nx])
				{
					visited[ny][nx] = true;
					board[ny][nx] = 'X';
					q.push({ ny,nx });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (board[i][j] == 'X' ? 'X' : '.');
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


