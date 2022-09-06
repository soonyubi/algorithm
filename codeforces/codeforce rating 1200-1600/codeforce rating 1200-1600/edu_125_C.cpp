
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
	int n; string s;
	cin >> n >> s;
	int cnt = 0;
	int rest = 0;
	vector<int> pos;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ')') pos.push_back(i);
	}
	for (int i = 0; i < n;)
	{
		if (s[i] == '(')
		{
			if (i == n - 1)
			{
				cout << cnt << " " << 1 << "\n";
				return;
			}
			cnt++;
			i += 2;
		}
		else
		{
			if (i == pos.back())
			{
				cout << cnt << " " << n - i << "\n";
				return;
			}
			int next = upper_bound(pos.begin(), pos.end(), i)-pos.begin();
			cnt++;
			i = pos[next]+1;
		}
	}
	cout << cnt << " 0\n";
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


