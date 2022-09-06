
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
	int zero = 0, five = 0,other =0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i] % 10 == 0) zero++;
		else if (v[i] % 10 == 5) five++;
		else other++;
	}
	if ((zero && other) || (five && other) || (zero && five && other))
	{
		cout << "NO\n";
		return;
	}
	if (five == n)
	{
		for (int i = 0; i < n; i++)
		{
			v[i] += 5;
		}
		for (int i = 0; i < n-1; i++)
		{
			if (v[i] != v[i + 1])
			{
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
		return;
	}
	if (zero == n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i] != v[i + 1])
			{
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
		return;
	}
	if (five + zero == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (v[i] % 10 == 5) v[i] += 5;
		}
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i] != v[i + 1])
			{
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		while (v[i] % 10 != 2)
		{
			v[i] = v[i] + (v[i] % 10);
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (abs(v[i + 1] - v[i]) % 20 == 0)
		{
			continue;
		}
		else
		{
			cout << "NO\n";
			return;
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


