
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
const int maxn = 201010;
vector<pll> adj_a[maxn];
vector<pll> adj_b[maxn];
void solve()
{
	int n; cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int p, a, b; cin >> p >> a >> b;
		adj_a[p].push_back({ i,a });
		adj_a[i].push_back({ p,a });
		adj_b[p].push_back({ i,b });
		adj_b[i].push_back({ p,b });
	}

	vector<ll> dist(n + 1, 0);
	vector<bool> visited(n + 1, false);
	queue<pll> q; 
	q.push({ 1,0 });
	visited[1] = true;

	while (!q.empty())
	{
		ll v = q.front().first;
		ll c = q.front().second;
		q.pop();

		for (auto x : adj_a[v])
		{
			ll nv = x.first;
			ll nc = x.second + c;

			if (!visited[nv])
			{
				visited[nv] = true;
				dist[nv] = nc;
				q.push({ nv,nc });
			}
		}
	}
	vector<int> ans(n + 1, 0);
	for (int i = 1; i <= n; i++) visited[i] = false;
	vector<ll> path;
	queue<pair<vector<ll>, pll>> q2;
	q2.push({ path,{1,0} });
	visited[1] = true;

	while (!q2.empty())
	{
		ll v = q2.front().second.first;
		ll c = q2.front().second.second;
		auto path = q2.front().first;
		q2.pop();

		for (auto x : adj_b[v])
		{
			ll nv = x.first;
			ll nc = c + x.second;
			
			path.push_back(nc);

			if (!visited[nv])
			{
				visited[nv] = true;
				if (path.back() <= dist[nv]) ans[nv] = path.size();
				else
				{
					auto it = lower_bound(path.begin(), path.end(), dist[nv]) - path.begin();
					if (it == path.size()) ans[nv] = 0;
					else
					{
						ans[nv] = it - 1;
					}
				}
				q2.push({ path,{nv,nc} });
			}
		}
	}
	
	for (int i = 2; i <= n; i++)
	{
		cout << ans[i] << " ";
	}cout << "\n";

	for (int i = 0; i <= n; i++)
	{
		adj_a[i].clear();
		adj_b[i].clear();
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


