
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
	int n, m; cin >> n >> m;
	vector<int> dist;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int d1 = abs(i - n) + abs(j - m);
			int d2 = abs(i - 1) + abs(j - 1);
			int d3 = abs(i - 1) + abs(j - m);
			int d4 = abs(i - n) + abs(j - 1);
			int d = max(d1, d2);
			d = max(d, d3);
			d = max(d, d4);
			dist.push_back(d);
			
		}
	}
	sort(dist.begin(), dist.end());
	for (auto u : dist)
	{
		cout << u << " ";
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


