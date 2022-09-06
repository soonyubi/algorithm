
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
int in[200001];

void solve()
{
	int n; cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int a, b; cin >> a >> b;
		if (in[a] < 2 && in[b] < 2)
		{
			in[a]++; in[b]++;
			adj[a].push_back(i);
			adj[b].push_back(i);
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 2) ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (auto u : ans) cout << u << " ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


