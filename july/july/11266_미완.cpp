
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

const int maxn = 1e5 + 1;
int V, E, cnt;
int dfsn[maxn];
vector<int> adj[maxn];
vector<pii> stk;
vector<vector<pii>> BCC;

int dfs(int cur, int prev)
{
	dfsn[cur]++;
	int result = dfsn[cur];

	for (auto nv : adj[cur])
	{
		if (nv == prev) continue;
		
		// 아직 방문하지 않은 간선 
		if (dfsn[nv] < dfsn[cur]) stk.push_back({ cur,nv });
		
		// 역방향간선
		if (dfsn[nv] > 0) result = min(result, dfsn[nv]);
		// 트리간선
		else
		{
			int temp = dfs(nv, cur);
			result = min(result, temp);

			// nv가 dfs 트리상에서 cur의 조상으로 갈 수 없음 : 새로운 BCC 발견
			if (temp >= dfsn[cur])
			{
				BCC.emplace_back();
				while (true)
				{
					pii e = stk.back();
					stk.pop_back();
					BCC.back().push_back(e);

					if (e == pii(cur, nv)) break;
				} 
				
			}
		}
		
	}
	return result;
}
void solve()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) if (!dfsn[i]) dfs(i,-1);

	cout << BCC.size() << "\n";
	int cnt = 1;
	for (auto u : BCC)
	{
		cout << cnt++ << "\n";
		for (auto edge : u)
		{
			cout << edge.first << " " << edge.second << "\n";
		}
		cout << "--------------------------\n";
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


