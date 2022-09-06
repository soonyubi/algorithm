
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
	ll n, m; cin >> n >> m;
	if (n % 2 == 1 && m % 2 == 0)
	{
		cout << "Burenka\n";
	}
	else if (n % 2 == 1 && m % 2 == 1)
	{
		cout << "Tonya\n";
	}
	else if (n % 2 == 0 && m % 2 == 0)
	{
		cout << "Tonya\n";
	}
	else
	{
		cout << "Burenka\n";
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


