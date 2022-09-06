
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
int cnt[200001];
void solve()
{
	for (int i = 0; i < 200001; i++) cnt[i] = 0;
	int n; cin >> n;
	vector<int> v(n);
	for (int& x : v) cin >> x;
	for (int i = n - 1; i >= 0; i--)
	{
		if (cnt[v[i]]==0)
		{
			cnt[v[i]]++;
			continue;
		}
		else
		{
			cout << i+1 << "\n";
			return;
		}
	}
	cout << 0 << "\n";
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


