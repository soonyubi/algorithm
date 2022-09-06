
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
const int S = 1, T = 26;
const int maxn = 60;
const int INF = 987654321;

int flow[maxn][maxn];
bool visited[maxn];

int dfs(int v, int cf)
{
	visited[v] = true;
	if (v == T) return cf;

	for (int nv = 0; nv < maxn; nv++)
	{
		if (visited[nv]) continue;
		if (!flow[v][nv]) continue;
		int res = dfs(nv, min(cf, flow[v][nv]));
		if (res)
		{
			flow[v][nv] -= res;
			flow[nv][v] += res;
			return res;
		}
	}
	return 0;
}
int c2i(char c)
{
	if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
	else
	{
		return c - 'a' + 27;
	}
}
void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a,b; int w; cin >> a >> b >> w;
		int u = c2i(a), v = c2i(b);
		flow[u][v] += w;
		flow[v][u] += w;
	}

	int ans = 0;
	while (true)
	{
		memset(visited, false, sizeof(visited));
		int res = dfs(S, INF);
		if (res == 0) break;
		ans += res;
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


