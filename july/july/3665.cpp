
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
vector<int >adj[501];
int indegree[501];
void solve()
{
	int n; cin >> n;
	vector<vector<bool>> chk(n + 1, vector<bool>(n + 1, false));
	vector<int> rank(n);
	for (int& x : rank) cin >> x;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			chk[rank[i]][rank[j]] = true;
			indegree[rank[j]]++;
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		if (chk[a][b])
		{
			chk[a][b] = false;
			chk[b][a] = true;
			indegree[b]--;
			indegree[a]++;
		}
		else
		{
			chk[b][a] = false;
			chk[a][b] = true;
			indegree[a]--;
			indegree[b]++;
		}
		
	}
	
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) pq.push(i);
	}
	int flag = 2;
	vector<int> topology;
	for (int i = 0; i < n; i++)
	{
		if (pq.empty())
		{
			flag = 0;
			break;
		}
		if (pq.size() > 1)
		{
			flag = 1;
			break;
		}
		int v = pq.top();
		pq.pop();
		
		topology.push_back(v);
		

		for (int i = 1; i <= n; i++)
		{
			if (chk[v][i])
			{
				if (--indegree[i] == 0)
				{
					pq.push(i);
				}
			}
		}
	}
	if (flag == 0)
	{
		cout << "IMPOSSIBLE\n";
	}
	else if (flag == 1)
	{
		cout << "?\n";
	}
	else
	{
		for (auto u : topology)
		{
			cout << u << " ";
		}cout << "\n";
	}
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


