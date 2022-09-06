
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
const int inf = 1e9 + 7;
class MCMF
{
public:
	int n, s, e;
	vector<vector<int>> c, f,d, adj;
	MCMF() { n = 0, s = e = -1; }
	MCMF(int n) { 
		this->n = n;
		c.resize(n+1);
		f.resize(n + 1);
		d.resize(n + 1);
		adj.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			c[i].resize(n + 1,0);
			f[i].resize(n + 1,0);
			d[i].resize(n + 1,0);
		}
		s = e = -1;
	}
	MCMF(int n,int s,int e) 
	{
		this->n = n; this->s = s; this->e = e;
		c.resize(n + 1);
		f.resize(n + 1);
		d.resize(n + 1);
		adj.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			c[i].resize(n + 1, 0);
			f[i].resize(n + 1, 0);
			d[i].resize(n + 1, 0);
		}
	}

	void setSource(int s) { this->s = s; }
	void setSink(int t) { this->e = t; }
	void addEdge(int u, int v, int cap, int dist)
	{
		adj[u].push_back(v); c[u][v] = cap; d[u][v] = dist;
		adj[v].push_back(u); c[v][u] = 0; d[v][u] = -dist;
	}

	pii mcmf()
	{
		int minCost = 0;
		int ret = 0;
		vector<int> par(n + 1, -1);
		vector<int> dist(n + 1, inf);
		vector<bool> inque(n + 1, false);
		while (true)
		{
			fill(par.begin(), par.end(), -1);
			fill(dist.begin(), dist.end(), inf);
			fill(inque.begin(), inque.end(), 0);
			queue<int> q;
			q.push(s);
			dist[s] = 0;
			inque[s] = 1;

			while (!q.empty())
			{
				int v = q.front(); q.pop();
				inque[v] = 0;

				for (auto nv : adj[v])
				{
					if (c[v][nv] - f[v][nv] > 0 && dist[nv] > dist[v] + d[v][nv])
					{
						dist[nv] = dist[v] + d[v][nv];
						par[nv] = v;
						if (!inque[nv])
						{
							q.push(nv);
							inque[nv] = 1;
						}
					}
				}
			}
			if (par[e] == -1) break;

			int flow = inf;

			for (int i = e; i != s; i = par[i])
			{
				int a = par[i], b = i;
				flow = min(flow, c[a][b] - f[a][b]);
			}
			ret += flow;
			for (int i = e; i != s; i = par[i])
			{
				int a = par[i], b = i;
				minCost += flow * d[a][b];
				f[a][b] += flow;
				f[b][a] -= flow;
			}
		}
		return {ret,minCost};
	}
};

void solve()
{
	
	int n, m; cin >> n >> m; 
	const int bias = 100;
	const int S = 201, T = 202;
	MCMF flow(222, S, T);
	
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		flow.addEdge(i + bias, T, x, 0);
	}
	for (int i = 1; i <= m; i++)
	{
		int x; cin >> x;
		flow.addEdge(S, i, x, 0);
	}
	vector<vector<int>> cap(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> cap[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int d; cin >> d;
			flow.addEdge(i, bias + j, cap[i][j], d);
		}
	}
	pii ans = flow.mcmf();
	cout << ans.first <<"\n" << ans.second << "\n";
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


