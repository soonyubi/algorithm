
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
int cnt[26];
void solve()
{
	string s; cin >> s;
	memset(cnt, 0, sizeof(cnt));
	for (auto u : s)
	{
		if (u >= 'a' && u <= 'z') cnt[u - 'a']++;
		else if (u >= 'A' && u <= 'Z') cnt[u - 'A']++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (cnt[i] != cnt[25 - i])
		{
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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


