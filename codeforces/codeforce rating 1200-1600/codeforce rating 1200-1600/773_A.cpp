
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
map<int, int> mp;

void solve()
{
	int n, x; cin >> n >> x;
	vector<int>v(n);
	for (int& x : v)
	{
		cin >> x;
		mp[x]++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		if (mp.count(v[i] * x))
		{
			mp[v[i] * x]--;
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


