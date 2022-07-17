
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
	int g; cin >> g;
	set<pii> s;
	for (int i = 1; i <= g; i++)
	{
		if (g % i == 0)
		{
			int x = i; int y = g / i;
			if (x > y) swap(x, y);
			s.insert({ x,y });
		}
	}
	vector<int> ans;
	for (auto& u : s)
	{
		if ((u.first + u.second) % 2 == 0)
		{
			int t1 = (u.first + u.second) / 2;
			int t2 = (u.second - u.first) / 2;
			if (t1 != 0 && t2 != 0)
			{
				ans.push_back(t1);
			}
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty())
	{
		cout << "-1\n";
		return;
	}
	for (auto& u : ans)
	{
		cout << u << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


