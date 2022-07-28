
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

int cnt;
vector<int> adj[20001];
int dfs_num[20001];
int scc_num[20001];
bool finished[20001];
vector<int> stk;
vector<vector<int>> SCC;
int k, n;

int dfs(int x)
{
	dfs_num[x] = ++cnt;
	stk.push_back(x);

	int result = dfs_num[x];
	for (auto nv : adj[x])
	{

		if (!dfs_num[nv]) result = min(result, dfs(nv));
		else if (!finished[nv]) result = min(result, dfs_num[nv]);
	}


	if (result == dfs_num[x])
	{
		SCC.emplace_back();
		while (true)
		{
			int t = stk.back(); stk.pop_back();
			SCC.back().push_back(t);
			finished[t] = true;
			scc_num[t] = SCC.size() - 1;
			if (t == x) break;
		}
		//sort(SCC.back().begin(), SCC.back().end());
	}
	return result;
}

int f(int x)
{
	if (x > 0) return x;
	return -x + k;
}

void solve()
{
	 cin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c; char c1,c2,c3;
		cin >> a >> c1;
		cin >> b >> c2;
		cin >> c >> c3;
		if (c1 == 'B') a = -a;
		if (c2 == 'B') b = -b;
		if (c3 == 'B') c = -c;
		// ~a -> c , ~c -> a
		adj[f(-a)].push_back(f(c));
		adj[f(-c)].push_back(f(a));
		// ~a->b, ~b -> a
		adj[f(-a)].push_back(f(b));
		adj[f(-b)].push_back(f(a));
		// ~c->b, ~b->c
		adj[f(-c)].push_back(f(b));
		adj[f(-b)].push_back(f(c));
	}

	for (int i = 1; i <= 2 * k; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}

	for (int i = 1; i <= k; i++)
	{
		if (scc_num[i] == scc_num[i + k])
		{
			cout << "-1\n";
			return;
		}
	}

	for (int i = 1; i <= k; i++)
	{
		if (scc_num[i + k] > scc_num[i]) cout << "R";
		else cout << "B";
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


