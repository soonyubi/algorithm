
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
int board[111][111];
int color[111][111];
bool visited[111][111];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
int n, m;
bool isRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	return false;
}
struct P
{
	int y, x, d;
};
void labeling(int y, int x,int c)
{
	queue<pii> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		color[cy][cx] = c;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (!isRange(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (board[ny][nx] != board[cy][cx]) continue;
			
			visited[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}
void solve()
{
	 cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c; cin >> c;
			board[i][j] = c - '0';
			color[i][j] = -1;
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && board[i][j] > 0)
			{
		
				labeling(i, j, c); c++;
			}
		}
	}
	if (c == 1)
	{
		cout << "0\n";
		return;
	}
	
	queue<P> q;
	memset(visited, false, sizeof(visited));
	vector<bool> check(c, false);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] > 0)
			{
				P now; now.x = i; now.y = j; now.d = 0;
				q.push(now);
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		int v = board[y][x];
		q.pop();
		
		int cnt = 0;
		for (int i = 0; i < c; i++) if (!check[i]) cnt++;
		if (cnt == 0)
		{
			cout << d << "\n";
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				int ny = y + dy[i] * j;
				int nx = x + dx[i] * j;
				P nxt; nxt.y = ny, nxt.x = nx, nxt.d = d + 1;
				if (!isRange(ny, nx)) break;
				if (visited[ny][nx]) break;
				if (board[ny][nx] == 0)
				{
					board[ny][nx] = v;
					visited[ny][nx] = true;
					q.push(nxt);
				}
				else
				{
					if (check[color[y][x]] && check[color[ny][nx]]) break;
					check[color[y][x]] = check[color[ny][nx]] = true;
					if (board[ny][nx] < board[y][x])
					{
						board[ny][nx] = board[y][x];
						visited[ny][nx] = true;
						q.push(nxt);
					}
				}

			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


