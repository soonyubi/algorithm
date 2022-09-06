
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
const int inf = 1e9;
class FordFulkerson
{
private:
	int s, e, n; 
	vector<vector<int>> adj, c, f;
public:

	FordFulkerson() { n = 0, s = -1, e = -1; }
	FordFulkerson(int n)
	{
		this->n = n;
		f.resize(n + 1), c.resize(n + 1), adj.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			f[i].resize(n + 1);
			c[i].resize(n + 1);
		}
		s = e = -1;
	}
	FordFulkerson(int n, int s, int e)
	{
		this->n = n;
		f.resize(n + 1), c.resize(n + 1), adj.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			f[i].resize(n + 1);
			c[i].resize(n + 1);
		}
		this->s = s; this->e = e;
	}
	void setSource(int s) { this->s = s; }
	void setSink(int t) { this->e = t; }
	void addEdge(int u, int v, int cap, bool directed)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] += cap;
		if (!directed) c[v][u] += cap;
	}
	int maxFlow()
	{
		vector<int> par(n + 1);
		int ret = 0;
		queue<int> q;
		while (true)
		{
			fill(par.begin(), par.end(), -1);
			q = queue<int>(); q.push(s);
			while (!q.empty())
			{
				int v = q.front(); q.pop();
				for (auto nv : adj[v])
				{
					if (par[nv] == -1 && c[v][nv] - f[v][nv] > 0)
					{
						q.push(nv);
						par[nv] = v;
						
					}
				}
			}

			if (par[e] == -1) break;
			int cost = inf;

			for (int i = e; i != s; i = par[i])
			{
				int a = par[i], b = i;
				cost = min(cost, c[a][b] - f[a][b]);
			}

			ret += cost;
			for (int i = e; i != s; i = par[i])
			{
				int a = par[i], b = i;
				f[a][b] += cost;
				f[b][a] -= cost;
			}
		}

		return ret;
	}
};

void solve()
{
	int n, k, d; cin >> n >> k >> d;
	const int S = 301, T = 302;
	const int bias = 200;
	FordFulkerson flow (333, S, T);
	for (int i = 1; i <= n; i++)
	{
		flow.addEdge(S, i, k, 1);
	}
	for (int i = 1; i <= d; i++)
	{
		int x; cin >> x;
		flow.addEdge(i + bias, T, x, 1);
	}
	for (int i = 1; i <= n; i++)
	{
		int sz; cin >> sz;
		for (int j = 0; j < sz; j++)
		{
			int x; cin >> x;
			flow.addEdge(i, x + bias, 1, 1);
		}
	}

	cout << flow.maxFlow() << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


