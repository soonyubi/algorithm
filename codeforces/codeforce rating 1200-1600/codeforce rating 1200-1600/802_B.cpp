
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
	if (s[0] == '9')
	{
		vector<char> p(n + 1, '1');
		reverse(s.begin(), s.end());
		for (int i = 0; i < n; i++)
		{
			if (p[i] < s[i])
			{
				p[i + 1]--;
				p[i] = (int)p[i] - (int)s[i] + 10 + '0';
			}
			else
			{
				p[i] = (int)p[i] - (int)s[i] + '0';
			}
		}
		reverse(p.begin(), p.begin() + n);
		for (int i = 0; i < n; i++) cout << p[i];
		cout << "\n";
	}
	else
	{
		vector<char> p(n, '9');
		for (int i = 0; i < n; i++)
		{
			p[i] = (int)p[i] - (int)s[i] + '0';
		}
		for (int i = 0; i < n; i++) cout << p[i];
		cout << "\n";
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


