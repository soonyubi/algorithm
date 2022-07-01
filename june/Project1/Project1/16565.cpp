
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
int comb[53][53];
const int MOD = 10007;
void solve()
{
	for (int i = 0; i < 53; i++) comb[i][0] = 1;
	for (int i = 1; i < 53; i++)
	{
		for (int j = 1; j < 53; j++)
		{
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
	int ans = 0;
	int n; cin >> n;
	for (int i = 1; i <= 13 && n - 4 * i >= 0; i++)
	{
		if (i % 2 == 1)
		{
			ans = (ans + comb[13][i] * comb[52 - 4 * i][n - 4 * i]) % MOD;
		}
		else
		{
			ans = ((ans - comb[13][i] * comb[52 - 4 * i][n - 4 * i]) % MOD + MOD) % MOD;
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

