
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

int c[111][111];
int f[111][111];
int bias = 50;
int n;
vector<int> adj[111];
int par[111];

int row[111], col[111];
int rowsum, colsum;

int s = 101, e = 102;

void init(int x)
{
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			c[i][j + bias] = x;
		}
	}
}

bool chk(int mid)
{
	init(mid);
	int res = 0;
	while (1)
	{
		memset(par, -1, sizeof(par));
		queue<int> q; q.push(s);
		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (auto nv : adj[v])
			{
				if (par[nv] == -1 && c[v][nv] - f[v][nv] > 0)
				{
					par[nv] = v;
					q.push(nv);
				}
			}
		}
		if (par[e] == -1) break;
		int cost = 1e9 + 8;
		for (int i = e; i != s; i = par[i])
		{
			int a = par[i], b = i;
			cost = min(cost, c[a][b] - f[a][b]);
		}

		res += cost;
		for (int i = e; i != s; i = par[i])
		{
			int a = par[i], b = i;
			f[a][b] += cost;
			f[b][a] -= cost;
		}
		
	}
	return rowsum==colsum && res == rowsum;
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> row[i];
	for (int i = 1; i <= n; i++) cin >> col[i];
	for (int i = 1; i <= n; i++)
	{
		rowsum += row[i];
		colsum += col[i];
		adj[s].push_back(i);
		adj[i + bias].push_back(e);
		c[s][i] = row[i];
		c[i + bias][e] = col[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			adj[i].push_back(j + bias);
			adj[j + bias].push_back(i);
		}
	}

	int lo = 0, hi = 10000; int ans = -1;
	while (lo <= hi)
	{
		int mid = lo + hi >> 1;
		if (chk(mid))
		{
			ans = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << ans << "\n";
	chk(ans);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << f[i][j + bias] << " ";
		}cout << "\n";
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


