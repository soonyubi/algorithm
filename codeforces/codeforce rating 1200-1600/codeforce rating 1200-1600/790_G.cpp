
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
int indegree[4001];
int adj[4001];
char color[4001];
void solve()
{
	int n; cin >> n;
	for (int i = 0; i <= n; i++)
	{
		adj[i] = color[i] = indegree[i] = 0;
	}
	for (int i = 2; i <= n; i++)
	{
		int x; cin >> x;
		adj[i] = x;
		indegree[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> color[i];
	}
	queue<int> q; 
	vector<pll> cnt(n + 1, { 0,0 });
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == 'B') cnt[i] = { 1,0 };
		else cnt[i] = { 0,1 };
		if (indegree[i] == 0)
		{
			q.push(i);
			
		}
	}
	

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		int nv = adj[v];
		cnt[nv].first += cnt[v].first;
		cnt[nv].second += cnt[v].second;
		if (--indegree[nv]==0)
		{
			
			q.push(nv);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i].first == cnt[i].second) ans++;
	}
	cout << ans << "\n";
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


