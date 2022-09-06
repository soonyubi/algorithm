
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

vector<ll> xx[100001];
vector<ll> yy[100001];
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x; cin >> x;
			xx[x].push_back(i);
			yy[x].push_back(j);
		}
	}
	ll ans = 0;
	for (int i = 0; i < 100001; i++)
	{
		if (xx[i].empty()) continue;
		sort(xx[i].begin(), xx[i].end());
		sort(yy[i].begin(), yy[i].end());

		ll temp = 0;
		ll cnt = 0;
		ll sz = xx[i].size();
		for (int j = 0; j < sz; j++)
		{
			cnt++;
			temp += xx[i][j];
			ans += cnt * xx[i][j] - temp;
		}
		cnt = 0;
		temp = 0;
		for (int j = 0; j < sz; j++)
		{
			cnt++;
			temp += yy[i][j];
			ans += cnt * yy[i][j] - temp;
		}
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


