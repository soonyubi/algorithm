
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
vector<int> adj[maxn];
int degree[maxn];
bool visited[maxn];
vector<int> ans;
map<pii, int> mp;

void dfs(int x, int w)
{
	visited[x] = true;
	for (auto nx : adj[x])
	{
		if (!visited[nx])
		{
			int nw = (w == 2 ? 3 : 2);
			ans[mp[{x, nx}]] = nw;
			dfs(nx, nw);
		}
	}
}

void solve()
{
	int n; cin >> n;
	ans.clear();
	mp.clear();
	for (int i = 0; i <= n; i++)
	{
		adj[i].clear();
		degree[i] = visited[i] = 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		if (a == b) continue;
		mp[{a, b}] = i;
		mp[{b, a}] = i;
		adj[a].push_back(b);
		adj[b].push_back(a);
		degree[a]++; degree[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] > 2)
		{
			cout << "-1\n";
			return;
		}
	}

	ans = vector<int>(n - 1);
	
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 1)
		{
			dfs(i, 2);
		}
	}
	
	for (auto u : ans)
	{
		cout << u << " ";
	}cout << "\n";

	

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


