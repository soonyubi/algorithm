
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

class FordFulkerson
{
private:
	vector<vector<int>> flow, capacity, adj;
	int s, e, n; // src, sink, vertices
public :
	FordFulkerson() { n = 0, s = -1, e = -1; }
	FordFulkerson(int n)
	{
		this->n = n;
		flow.resize(n + 1), capacity.resize(n + 1), adj.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			flow[i].resize(n + 1);
			capacity[i].resize(n + 1);
		}
		s = e = -1;
	}
	FordFulkerson(int n, int s, int e)
	{
		this->n = n;
		flow.resize(n + 1), capacity.resize(n + 1), adj.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			flow[i].resize(n + 1);
			capacity.resize(n + 1);
		}
		this->s = s; this->e = e;
	}
	void setSource(int s) { this->s = s; }
	void setSink(int t) { this->e = t; }
	void addEdge(int start, int end, int cap, bool directed)
	{
		adj[start].push_back(end);
		adj[end].push_back(start);
		capacity[start][end] += cap;
		if (!directed) capacity[end][start] += cap;
	}
	int maxFlow()
	{
		if (s == -1 || e == -1) return -1;
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
					if (par[nv] == -1 && capacity[v][nv] - flow[v][nv] > 0)
					{
						q.push(nv); 
						par[nv] = v;
						if (nv == e) break;
					}
				}
			}
			if (par[e] == -1) break;
			int cost = inf;
			for (int i = e; i != s; i = par[i])
			{
				int a = par[i], b = i;
				cost = min(cost, capacity[a][b] - flow[a][b]);
			}
			ret += cost;
			for (int i = e; i != s; i = par[i])
			{
				int a = par[i], b = i;
				flow[a][b] += cost; flow[b][a] -= cost;
			}
		}
		return ret;
	}
};

void solve()
{

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


