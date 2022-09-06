
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
const int maxn = 200001;
int in[maxn];
int par[maxn];
bool visited[maxn];
vector<vector<int>> ans;
void dfs(int x)
{
	visited[x] = true;
	ans.back().push_back(x);
	int nv = par[x];
	if (!visited[nv])
	{
		dfs(nv);
	}
}
void solve()
{
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		par[i] = x;
		in[x]++;
		if (i == x) in[x]--;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		if (in[i] == 0)
		{
			
			ans.emplace_back();
			dfs(i);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].size() << "\n";
		for (auto u : ans[i])
		{
			cout << u << " ";
		}cout << "\n";
	}

	for (int i = 0; i < ans.size(); i++) ans[i].clear();
	ans.clear();
	for (int i = 0; i <= n; i++)
	{
		in[i] = par[i] = visited[i] = 0;
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


