
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
	int n, k; cin >> n >> k;
	vector<int> v(n);
	vector<int> cnt(k + 1, 0);
	for (int& x : v)
	{
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1; i <= k; i++)
	{
		if (cnt[i] == 0)
		{
			cout << "1\n";
			return;
		}
	}
	fill(cnt.begin(), cnt.end(), 0);
	int temp_k = k;
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (cnt[v[i]]) continue;
		cnt[v[i]]++;
		temp_k--;
		if (temp_k == 0)
		{
			fill(cnt.begin(), cnt.end(), 0);
			ans++;
			temp_k = k;
		}
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


