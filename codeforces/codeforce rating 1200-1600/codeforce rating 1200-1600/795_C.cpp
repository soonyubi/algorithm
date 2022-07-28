
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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int ans = 0; int cnt = 0;
	int pf = n, pl = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != '1') continue;
		cnt++;
		if (pf == n) pf = i;
		pl = i;
	}
	int add = 0;
	if (cnt > 0 && (n - 1 - pl) <= k)
	{
		k -= (n - 1 - pl);
		add++;
		cnt--;
	}
	if (cnt > 0 && pf <= k)
	{
		k -= pf;
		add += 10;
		cnt--;
	}
	cout << cnt * 11 + add << "\n";
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


