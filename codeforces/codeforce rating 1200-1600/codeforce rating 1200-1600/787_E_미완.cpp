
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
	string s; cin >> s;
	char mn = 'a';

	for (int i = 0; i < n; i++)
	{
		if (s[i] > mn)
		{
			k -= mn - 'a';
			int to = s[i] - k;
			for (char c = s[i]; c > to; c--)
			{
				for (char& e : s) if (e == c) e = char(c - 1);
			}
			break;
		}
		else s[i] 
	}
	
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


