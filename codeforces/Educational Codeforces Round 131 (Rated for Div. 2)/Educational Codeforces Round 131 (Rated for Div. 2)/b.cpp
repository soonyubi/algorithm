
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

	vector<bool> check(n + 1, false);
	vector<int> ans;
	for (int i = 1; i <= n; i=(i<<1))
	{
		ans.push_back(i);
		check[i] = true;
	}
	reverse(ans.begin(), ans.end());
	for (int i = n; i >= 1; i--)
	{
		if (check[i]) continue;
		if (i % 2 != 0) continue;
		for (int j = i; j >= 1; j/=2)
		{
			if (check[j]) break;
			ans.push_back(j);
			check[j] = true;
			if (j % 2 != 0) break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!check[i]) ans.push_back(i);
	}
	reverse(ans.begin(), ans.end());
	cout << "2\n";
	for (auto u : ans)
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


