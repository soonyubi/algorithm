
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
	ll n; ll x, y, xx, yy; 
	cin >> n >> x >> y >> xx >> yy;
	if (x > xx || y > yy)
	{
		cout << "-1\n";
		return;
	}
	
	ll dx = xx - x;
	ll dy = yy - y;
	if (dx == dy)
	{
		if (n % 2 == 1)
		{
			cout << "-1\n";
			return;
		}
		else
		{
			for (int i = 0; i < n / 2; i++) cout << "R";
			for (int i = 0; i < n / 2; i++) cout << "U";
			return;
		}
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


