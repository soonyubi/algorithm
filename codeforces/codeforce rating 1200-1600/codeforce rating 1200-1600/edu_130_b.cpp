
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
	int n, q; cin >> n >> q;
	vector<ll> v(n);
	for (ll& x : v) cin >> x;
	sort(v.begin(), v.end());
	//reverse(v.begin(), v.end());
	vector<ll> psum(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		psum[i] = psum[i - 1] + v[i - 1];
	}


	for (int i = 0; i < q; i++)
	{
		int x, y; cin >> x >> y;
		cout << psum[n - x + y] - psum[n - x] << "\n";
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


