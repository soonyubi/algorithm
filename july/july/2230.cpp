
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
#define all(v) v.begin(),v.end()
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve()
{
	int n, m; cin >> n >> m;
	if (m == 0)
	{
		cout << "0\n";
		return;
	}
	vector<int> v(n);
	for (int& x : v) cin >> x;
	sort(all(v));
	int i = 0, j = 0;
	const int inf = 2e9+1010;
	int ans = inf;
	while (i <= j&&j<n)
	{
		if ((v[j] - v[i]) >= m)
		{
			ans = min(ans, v[j] - v[i]);
			i++;
		}
		else
		{
			j++;
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


