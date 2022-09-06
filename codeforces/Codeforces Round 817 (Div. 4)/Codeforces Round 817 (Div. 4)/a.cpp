
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
	string s; cin >> s;
	vector<int> cnt(26);
	bool T = false;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') cnt[s[i] - 'a']++;
		else cnt[s[i] - 'A']++;
		if (s[i] == 'T') T = true;
		if (s[i] != 'T' && s[i] >= 'A' && s[i] <= 'Z')
		{
			flag = true;
		}
	}
	if (flag)
	{
		cout << "NO\n";
		return;
	}
	if (n == 5)
	{
		if (cnt['t' - 'a'] == 1 && cnt['i' - 'a'] == 1 && cnt['m' - 'a'] == 1 && cnt['u' - 'a'] == 1 && cnt['r' - 'a'] == 1)
		{
			if (T)
			{
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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


