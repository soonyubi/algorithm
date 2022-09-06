
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
ll k, x;
bool check1(ll mid)
{
	ll sum = mid * (mid + 1) / 2;
	return sum >= x;
}
bool check2(ll mid)
{
	ll sum = k * (k - 1) / 2 - (mid - 1) * mid / 2;
	cout << sum << "\n";
	return sum >= x;
}
void solve()
{
	 cin >> k >> x;
	if (k * k < x)
	{
		cout << 2*k-1 << "\n";
		return;
	}

	ll lo = 1, hi = k, ans = hi;

	if (k * (k + 1) / 2 >= x)
	{
		while (lo < hi)
		{
			ll mid = (lo + hi) / 2;
			if (check1(mid))
			{
				hi = mid - 1;
				ans = mid;
			}
			else
			{
				lo = mid + 1;
			}
		}
		cout << ans << "\n";
		
	}
	else
	{
		lo = 1, hi = k - 1, ans = hi;
		x -= k * (k + 1) / 2;
	
		while (lo < hi)
		{
			ll mid = (lo + hi) / 2;
			
			if (check2(mid))
			{
				lo = mid + 1;
				ans = mid;
			}
			else
			{
				hi = mid - 1;
			}
		}
		cout << ans + k<< "\n";
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


