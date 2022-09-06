
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
	int odd = 0, even = 0;
	vector<int> v(n);
	bool flag = true;
	bool one = false;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i] % 2 == 0) even++;
		else odd++;
		if (v[i] != v[0])flag = false;
		if (v[i] == 1) one = true;
	}
	if (flag || even == n || odd == n)
	{
		cout << "YES\n";
		return;
	}
	
	if (!one)
	{
		cout << "YES\n";
		return;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n - 1; i++)
	{
		if (v[i] + 1 == v[i + 1])
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


