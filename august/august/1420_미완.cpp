
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

vector<int> adj[22222];
map<pii, int> c;
map<pii, int> f;
char board[111][111];
bool visited[111][111];
int par[22222];
pii start_coor, end_coor;
int n, m;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
const int inf = 1e9 + 8;
const int bias = 10000;
int S, T;

int c2n(int y, int x)
{
	return y * m + x;
}
pii n2c(int x)
{
	return { x / m,x % m };
}
bool isRange(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	return false;
}
void addEdge(int s, int e, int x)
{
	adj[s].push_back(e); c[{s, e}] = x;
	adj[e].push_back(s); c[{e, s}] = 0;
}
int maxFlow()
{
	int ret = 0;
	queue<int> q;
	while (true)
	{
		memset(par, -1, sizeof(par));
		q = queue<int>(); q.push(S);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			for (auto nv : adj[v])
			{
				if (par[nv] == -1 && c[{v, nv}] - f[{v, nv}] > 0)
				{
					par[nv] = v;
					q.push(nv);
					if (nv == T+bias) break;
				}
			}
		}

		if (par[T+bias] == -1) break;

		
		ret++;

		for (int i = T; i != S; i = par[i])
		{
			int a = par[i], b = i;
			f[{a, b}]++;
			f[{b, a}]--;
		}
	}

	return ret;
}
void solve()
{
	start_coor = end_coor = { -1,-1 };
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'K') start_coor = { i,j };
			else if (board[i][j] == 'H') end_coor = { i,j };
		}
	}
	if (n == 1 && m == 1)
	{
		cout << "-1\n";
		return;
	}
	if (start_coor.first == -1 || end_coor.first == -1 || abs(start_coor.first - end_coor.first) + abs(start_coor.second - end_coor.second) == 1)
	{
		cout << "-1\n";
		return;
	}

	S = c2n(start_coor.first, start_coor.second);
	T = c2n(end_coor.first, end_coor.second);

	// in-out ¿¬°á
	for (int i = 0; i < n * m; i++)
	{
		addEdge(i, i + bias, 1);
	}
	
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<m;j++)
		{
			int u_in = c2n(i, j); int u_out = u_in + bias;
			if (i + 1 < n && board[i][j] != '#' && board[i + 1][j] != '#')
			{
				int v_in = c2n(i + 1, j); int v_out = v_in + bias;
				addEdge(u_out, v_in, inf);
				addEdge(v_out, u_in, inf);
			}
			if (j + 1 < m && board[i][j] != '#' && board[i][j+1] != '#')
			{
				int v_in = c2n(i,j+1); int v_out = v_in + bias;
				addEdge(u_out, v_in, inf);
				addEdge(v_out, u_in, inf);
			}
		}
	}

	for (auto u : c)
	{
		cout << u.first.first << " " << u.first.second << " " << u.second << "\n";
	}
	cout << maxFlow() << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


