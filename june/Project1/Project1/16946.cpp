
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
int visited[1001][1001];
int board[1001][1001];
int comp[1001][1001];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int n, m;
bool isRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	return false;
}
void bfs(int y, int x,int level)
{
	vector<pair<int, int>> path;
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	path.push_back({ y,x });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (!isRange(ny, nx)) continue;
			if (board[ny][nx] == 1) continue;
			if (visited[ny][nx]) continue;
			cnt++;
			visited[ny][nx] = 1;
			q.push({ ny,nx });
			path.push_back({ ny,nx });
		}
	}
	for (auto u : path)
	{
		visited[u.first][u.second] = cnt;
		comp[u.first][u.second] = level;
	}
	return;
}
void solve()
{
	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c; cin >> c;
			board[i][j] = c - '0';
			if (board[i][j] == 0) q.push({ i,j });
		}
	}
	int cnt_comp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 && !visited[i][j])
			{
				cnt_comp++;
				bfs(i, j,cnt_comp);
			}
		}
	}
	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1)
			{
				int temp = 1;
				vector<bool> cp(cnt_comp + 10, false);
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (isRange(ny, nx) && board[ny][nx] == 0&&!cp[comp[ny][nx]])
					{
						cp[comp[ny][nx]] = true;
						temp += visited[ny][nx];
					}
				}
				visited[i][j] = temp%10;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				visited[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visited[i][j];
		}cout << "\n";
	}
}
int main()
{
	solve();
	return 0;
}


