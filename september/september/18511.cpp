
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
	string n; cin >> n; int sz; cin >> sz;
	vector<bool> check(10, false);
	int mx = 0;
	for (int i = 0; i < sz; i++)
	{
		int x; cin >> x;
		check[i] = true;
		mx = max(mx, x);
	}

	bool flag = false;
	string ans;
	for (int i = 0; i < n.size(); i++)
	{
		if (flag) ans.push_back(mx);
		else
		{
			int j = n[i] - '0';
			for (; j >= 1; j--)
			{
				if (check[j]) break;
			}
			if (j != n[i] - '0') flag = true;
			ans.push_back(j + '0');
		}
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


