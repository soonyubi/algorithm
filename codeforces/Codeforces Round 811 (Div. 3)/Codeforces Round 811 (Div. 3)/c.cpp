
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
	int ans = 1e9;
	for (int i = 1; i < (1 << 9); i++)
	{
		int temp = 0;
		int sum = 0;
		for (int j = 0; j < 9; j++)
		{
			if ((1 << j) & i)
			{
				temp += j + 1;
				sum *= 10; 
				sum += j + 1;
			}
		}
		if (temp == n)
		{
			ans = min(ans, sum);
		}
	}
	cout << ans << "\n";
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


