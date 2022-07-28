
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
	vector<ll> v(n);
	ll sum = 0;
	for (ll& x : v)
	{
		cin >> x;
		sum += x;
	}
	if (sum != 0)
	{
		cout << "NO\n";
		return;
	}
	ll psum = 0;
	for (int i = 0; i < n; i++)
	{
		psum += v[i];
		if (psum < 0)
		{
			cout << "NO\n";
			return;
		}
		else if (psum == 0)
		{
			int j = i + 1;
			bool flag = true;
			for (; j < n; j++)
			{
				if (v[j] != 0)
				{
					flag = false;

				}
			}
			if (!flag)
			{
				cout << "NO\n";
				return;
			}
			break;
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


