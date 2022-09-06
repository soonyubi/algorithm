
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
	int n = 5; 
	vector<int> v(n);
	for (int& x : v) cin >> x;
	int ans = 1e9+7;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++)
	{
		
		int g = gcd(v[i], v[j]);
		int lcm_ab = g * (v[i] / g) * (v[j] / g);
		g = gcd(lcm_ab, v[k]);
		int lcm = lcm_ab * v[k] / g;
		ans = min(ans, lcm);
	}
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


