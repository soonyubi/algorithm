
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
	vector<int> v(n);
	for (int& x : v) cin >> x;
	if (k == 1)
	{
		cout << (n-1)/2 << "\n";
	}
	else
	{
		int cnt = 0;
		for(int i=1;i<n-1;i++)
		{
			if(v[i] > (v[i-1] + v[i+1])) cnt++;
		}
		cout << cnt << "\n";
	}
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


