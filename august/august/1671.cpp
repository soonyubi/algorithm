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
const int bias = 50;
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
		queue<int> q;
		int ret = 0;

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
						par[nv] = v;
						q.push(nv);
						if (e == nv) break;
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
				f[a][b] += cost; f[b][a] -= cost;
			}
		}
		return ret;
	}

};
struct P
{
	ll a, b, c;
};
void solve()
{
	int n; cin >> n;
	const int S = 101, T = 102;
	FordFulkerson flow(111, S, T);
	for (int i = 1; i <= n; i++)
	{
		flow.addEdge(S, i, 2, 1);
		flow.addEdge(i + bias, T, 1, 1);
	}
	vector<P> shark(n + 1);
	for (int i = 1; i <= n; i++)
	{
		P now; cin >> now.a >> now.b >> now.c;
		shark[i] = now;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			P s1 = shark[i]; P s2 = shark[j];
			if (s1.a == s2.a && s1.b == s2.b && s1.c == s2.c)
			{
				if (i < j) flow.addEdge(i, j + bias, inf, 1);
				continue;
			}
			if (s1.a >= s2.a&& s1.b >= s2.b&& s1.c >= s2.c)
			{
				flow.addEdge(i, j + bias, inf, 1);
			}
		}
	}
	cout << n - flow.maxFlow() << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


