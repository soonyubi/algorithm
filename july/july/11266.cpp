
/*
*   Time :
*   Subject : 단절점
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
const int MAXN = 10101;

int cnt;
vector<int> adj[MAXN];
bool isCutVertex[MAXN];
int discovered[MAXN]; // dfs 스패닝트리의 방문 순서

int dfs(int x, bool isRoot)
{
	discovered[x] = ++cnt;
	int ret = discovered[x];

	int nchild = 0;
	for (auto nv : adj[x])
	{
		if (!discovered[nv])
		{
			nchild++;
			int low = dfs(nv, false);
			if (!isRoot && low >= discovered[x])
			{
				isCutVertex[x] = true;
			}
			ret = min(ret, low);
		}
		else
		{
			ret = min(ret, discovered[nv]);
		}
	}
	if (isRoot)
		isCutVertex[x] = (nchild >= 2);
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

	for (int i = 1; i <= n; i++)
	{
		if (!discovered[i]) dfs(i, true);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isCutVertex[i]) ans++;
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i++)
	{
		if (isCutVertex[i]) cout << i << " ";
	}cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


