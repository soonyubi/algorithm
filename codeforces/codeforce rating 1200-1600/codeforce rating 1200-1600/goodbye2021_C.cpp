
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
#define ld long double
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve()
{
	int n; cin >> n;
	vector<ld> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	int ans = n - 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			
			int temp_ans = 0;
			for (int k = 1; k <= n; k++)
			{
				if ((v[j] - v[i]) * (k - i) != (v[k] - v[i]) * (j - i)) temp_ans++;
			}
			ans = min(ans, temp_ans);
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


