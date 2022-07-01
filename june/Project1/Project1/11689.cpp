
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

set<ll> s;

void getFact(ll n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		while (n % i == 0)
		{
			s.insert(i);
			n /= i;
			if (n == 0 || n==1) return;
		}
		
	}
	s.insert(n);
}

void solve()
{
	
	ll n; cin >> n;
	ll ans = n;
	getFact(n);
	if (n == 1)
	{
		cout << 1 << "\n";
		return;
	}
	for (auto u : s)
	{
		//cout << u << "\n";
		ans /= u;
		ans *= (u - 1);
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


