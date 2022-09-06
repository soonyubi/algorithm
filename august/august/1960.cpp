
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
vector<int> row, col;

class FordFulkerson
{
private:
	vector<vector<int>> flow, capacity, adj;
	int s, e, n; // src , sink, vertices
public:
	FordFulkerson() { n = 0, s = e = -1; }
	FordFulkerson(int n)
	{
		this->n = n;
		flow.resize(n + 1);
		capacity.resize(n + 1);
		adj.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			flow[i].resize(n + 1);
			capacity[i].resize(n + 1);
		}
		s = e = -1;
	}
	FordFulkerson(int n,int s,int e)
	{
		this->n = n; this->s = s; this->e = e;
		flow.resize(n + 1);
		capacity.resize(n + 1);
		adj.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			flow[i].resize(n + 1);
			capacity[i].resize(n + 1);
		}
	}
	vector<vector<int>> getFlow() { return this->flow; }
	void setSource(int s) { this->s = s; }
	void setSink(int t) { this->s = t; }
	void addEdge(int u, int v, int c, bool directed)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
		capacity[u][v] = c;
		if (!directed) capacity[v][u] = c;
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
				flow[a][b] += cost;
				flow[b][a] -= cost;
			}
		}
		return ret;
	}
	
	void printAnswer()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = n + 1; j <= 2 * n; j++)
			{
				cout << this->flow[i][j];
			}cout << "\n";
			
		}
	}
};

void solve()
{
	int n; cin >> n;
	const int S = 2 * n + 1;
	const int T = 2 * n + 2;
	row.resize(n + 1), col.resize(n + 1);

	FordFulkerson flow(2 * n + 10, S, T);
	
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		flow.addEdge(S, i, x, 1);
		row[i] = x;
	}
	for (int i = n + 1; i <= 2 * n; i++)
	{
		int x; cin >> x;
		flow.addEdge(i, T, x, 1);
		col[i - n] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = n + 1; j <= 2 * n; j++)
		{
			flow.addEdge(i, j, 1, 1);
		}
	}
	flow.maxFlow();
	vector<vector<int>> ans = flow.getFlow();
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = n + 1; j <= 2 * n; j++)
		{
			sum += ans[i][j];
		}
		if (sum != row[i]) {
			flag = false;
			break;
		}
	}

	// 열별로 같은지
	for (int j = n + 1; j <= 2 * n; j++)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += ans[i][j];
		}
		if (sum != col[j - n])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "1\n";
		for (int i = 1; i <= n; i++)
		{
			
			for (int j = n + 1; j <= 2 * n; j++)
			{
				cout << ans[i][j];
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "-1\n";
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


