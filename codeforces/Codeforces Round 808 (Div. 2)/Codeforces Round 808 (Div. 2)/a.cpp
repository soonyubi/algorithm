
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
	
	if (n == 2)
	{
		if ((v[0] < v[1]) && (v[1] % v[0] == 0))
		{
			cout << "YES\n";
		}
		else cout << "NO\n";
		return;
	}
	if (v[0]==1)
	{
		cout << "YES\n";
		return;
	}
	int idx = -1;
	for (int i = n - 1; i > 0; i--)
	{
		if (v[i] % v[i - 1] == 1)
		{
			idx = i;
		}
	}
	if (idx != 1)
	{
		cout << "NO\n";
		return;
	}
	else
	{
		if (v[idx] % v[0] == 1)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
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


