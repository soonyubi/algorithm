
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
	vector<int> cnt(26, 0);
	string s; cin >> s;
	for (auto c : s) cnt[c - 'a']++;
	
	int cntPairs = 0, cntOdd = 0;
	for (int c : cnt)
	{
		cntPairs += c / 2;
		cntOdd += c % 2;
	}

	int ans = (cntPairs / k) * 2;
	cntOdd += (cntPairs % k) * 2;
	if (cntOdd >= k)
	{
		ans++;
	}
	cout << ans << "\n";
	
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


