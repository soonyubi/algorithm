
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

int n, m;
int board[1001][1001];
bool cango[1001][1001][4]; // N E S W 
bool visited[1001][1001];

int dy[4] = { 0,1,0,-1};
int dx[4] = { -1,0,1,0 };

bool isRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	return false;
}
int bfs(int i, int j)
{
	int res = 0;
	queue<pii> q;
	q.push({ i,j });
	visited[i][j] = true;

	while (!q.empty())
	{
		res++;
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (cango[y][x][i] && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
	return res;
}
void solve()
{
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			for (int k = 0; k < 4; k++)
			{
				if ((board[y][x] & (1 << k)) == 0)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];
					int dir = (k + 2) % 4;
					if (!isRange(ny, nx)) continue;
					if ((board[ny][nx] & (1 << dir)) == 0)
					{
						cango[y][x][k] = true;
						cango[ny][nx][dir] = true;
					}
				}
			}
		}
	}


	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				int res = bfs(i, j);
				//cout << i << " " << j << " " << res << "\n";
				ans.push_back(res);
			}
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for (auto u : ans) cout << u << " "; cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


