
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve()
{
	int n; cin >> n;
	vector<ll> v(n);
	stack<pair<ll, ll>> s;
	for (int i = 0; i < n; i++) cin >> v[i];
	ll ans = 0;
	s.push({v[0],1});
	int x; // °°Àº Å°
	for (int i = 1; i < n; i++)
	{
		x = 1;
		while (!s.empty() && s.top().first <= v[i])
		{
			if (s.top().first < v[i])
			{
				ans += s.top().second;
				s.pop();
				x = 1;
			}
			else
			{
				ans += s.top().second;
				x = s.top().second + 1;
				s.pop();
			}
		}
		if (!s.empty()) ans++;
		s.push({ v[i],x });
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


