
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
const int MAXV = 101010;

vector<int> adj[MAXV];
int visited[MAXV];
vector<pii> cutEdge;
int cnt;
int dfs(int x, int par)
{
	visited[x] = ++cnt;
	int ret = visited[x];

	for (auto nv : adj[x])
	{
		if (nv == par) continue;
		if (!visited[nv])
		{
			int low = dfs(nv, x);
			if (low > visited[x])
			{
				cutEdge.push_back({ min(x,nv),max(x,nv) });
			}
			ret = min(ret, low);
		}
		else
		{
			ret = min(ret, visited[nv]);
		}
	}
	return ret;
}

void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);

	sort(cutEdge.begin(), cutEdge.end());
	cout << cutEdge.size() << "\n";
	for (auto u : cutEdge)
	{
		cout << u.first << " " << u.second << "\n";
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


