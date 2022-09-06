
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
	string s; cin >> s;
	int n = s.size();
	vector<bool> prev(26, false);
	int m = 0;
	for(auto& x : s)
	{ 
		if (prev[x - 'a'])
		{
			m += 2;
			for (int i = 0; i < 26; i++) prev[i] = false;
		}
		else
		{
			prev[x - 'a'] = true;
		}
	}
	cout << n - m << "\n";
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


