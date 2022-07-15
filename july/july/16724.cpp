
/*
*   Time :
*   Subject : dfs + union find 
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
char board[1001][1001];
int visited[1001][1001];
int par[1000001];
int height[1000001];
map<char, int> mp;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int getPar(int a)
{
	if (par[a] == -1) return a;
	else return par[a] = getPar(par[a]);
}
void merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);
	if (a == b) return;
	if (height[b] < height[a])
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
		if (height[b] == height[a])
		{
			height[b]++;
		}
	}
}

void dfs(int y, int x,int color)
{
	visited[y][x] = color;
	int dir = mp[board[y][x]];
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	
	//if (!isRange(ny, nx)) return;
	if (visited[ny][nx]==-1)
	{
		dfs(ny, nx, color);
	}
	else
	{
		if (visited[ny][nx] == visited[y][x]) return;
		else
		{
			merge(visited[y][x], visited[ny][nx]);
			return;
		}
	}
}
void solve()
{
	mp['U'] = 1; mp['D'] = 0; mp['R'] = 2; mp['L'] = 3;
	memset(par, -1, sizeof(par));
	memset(visited, -1, sizeof(visited));
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int color = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]==-1)
			{
				
				dfs(i, j, color);
				color++;
			}
		}
	}
	set<int> s;
	for (int i = 0; i < color; i++)
	{
		s.insert(getPar(i));
	}
	cout << s.size() << "\n";

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


