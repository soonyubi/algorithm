
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

int cache[200001];
int match[200001];
vector<int> adj[200001];

bool dfs(int v)
{
	cache[v] = true;
	for (auto nv : adj[v])
	{
		if (cache[match[nv]]) continue;
		if (match[nv] == 0 || dfs(match[nv]))
		{
			match[nv] = v;
			return true;
		}
	}
	return false;
}
void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{

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


