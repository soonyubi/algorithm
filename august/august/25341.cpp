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

ll len[2001];
ll from[2001][2001];
ll w[2001][2001];
ll bias[2001];
ll bias2;
ll weight[2001];


void solve()
{
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int sz; cin >> sz; len[i] = sz;
		for (int j = 1; j <= sz; j++)
		{
			cin >> from[i][j];
		}
		for (int j = 1; j <= sz; j++)
		{
			cin >> w[i][j];
		}
		cin >> bias[i];
	}

	for (int i = 1; i <= m; i++)
	{
		ll x; cin >> x;
		bias[i] *= x;
		for (int j = 1; j <= len[i]; j++)
		{
			weight[from[i][j]] += w[i][j] * x;
		}
	}
	cin >> bias2;
	
	//for (int i = 1; i <= n; i++) cout << weight[i] << "\n";
	for (int i = 0; i < q; i++)
	{
		ll ans = 0;
		for (int j = 1; j <= n; j++)
		{
			ll x; cin >> x;
			ans += weight[j] * x;
		}
		for (int j = 1; j <= m; j++) ans += bias[j];
		ans += bias2;
		cout << ans << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


