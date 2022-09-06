
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
	string s = "#";
	string o = "#";
	for (int i = 1; i <= n; i++)
	{
		char c; cin >> c;
		s += c;
		o += i + '0';
	}
	vector<ll> ans(n + 1,0);
	for (int i = n; i >= 1; i--)
	{
		if (s[i] == o[i])
		{
			ans[i] = 0;
			continue;
		}
		int idx = -1;
		for (int j = 1; j <= n; j++)
		{
			if (o[i] == s[j])
			{
				idx = j;
				break;
			}
		}
		ans[i] = (idx+i) % i;
		string temp = "#";
		temp += s.substr(idx + 1, i - idx);
		temp += s.substr(1, idx);
		temp += s.substr(i + 1, n - i);
		s = temp;
		cout << s << "\n";
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";

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


