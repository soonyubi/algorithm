
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
	vector<int> v(n);
	for (int& x : v) cin >> x;
	if (n % 2 == 1)
	{
		int temp = v[0];
		for (int i = 1; i < n; i += 2)
		{
			if (v[i] >= temp && v[i + 1] >= temp)
			{
				temp = max(v[i], v[i + 1]);
			}
			else
			{
				cout << "NO\n";
				return;
			}
		}
	}
	else
	{
		int temp = max(v[0], v[1]);
		for (int i = 2; i < n; i += 2)
		{
			if (v[i] >= temp && v[i + 1] >= temp)
			{
				temp = max(v[i], v[i + 1]);
			}
			else
			{
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
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


