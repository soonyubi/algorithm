
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
	vector<int> cnt(31, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		for (int j = 0; j < 30; j++)
		{
			if (v[i] & (1 << j)) cnt[j]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		bool flag = true;
		for (int j = 0; j < 30; j++)
		{
			if (cnt[j] % i != 0) flag = false;
		}
		if (flag) cout << i << " ";
	}
	cout << "\n";
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


