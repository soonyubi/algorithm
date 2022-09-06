
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
	int n, h, m; cin >> n >> h >> m;
	pii ans = {24,60 };
	for (int i = 0; i < n; i++)
	{
		int hi, mi; cin >> hi >> mi;
		pii temp;
		temp.first = hi - h;
		temp.second = mi - m;
		if (temp.first < 0) temp.first += 24;
		if (temp.second < 0) {
			if (temp.first > 0)
			{
				temp.first--;
				temp.second += 60;
			}
			else
			{
				temp.first += 24;
				temp.first--;
				temp.second += 60;
			}
		}
		ans = min(ans, temp);
	}
	cout << ans.first <<" " << ans.second << "\n";
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


