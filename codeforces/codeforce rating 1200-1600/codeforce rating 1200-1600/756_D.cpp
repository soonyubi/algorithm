
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
void solve()
{
	int n; cin >> n;
	vector<int> par(n + 1);
	int root = -1;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		par[i] = x;
		if (x == i) root = i;
	}
	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	if (p[1] != root)
	{
		cout << "-1\n";
		return;
	}
	vector<int> ans(n + 1,-1);
	ans[root] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (ans[par[p[i]]] == -1)
		{
			
			cout << "-1\n";
			return;
		}
		ans[p[i]] = ans[p[i - 1]] + 1;
		
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] - ans[par[i]]<< " ";
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


