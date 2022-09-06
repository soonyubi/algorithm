
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
	int n; char c; cin >> n >> c;
	string s; cin >> s;
	vector<bool> check(n + 1, false);
	s = " " + s;
	bool flag = true;
	check[1] = true;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] != c)
		{
			flag = false;
			check[i] = true;
			int temp = i;
			int j2 = sqrt(temp);
			for (int j = 2; j <= j2; j++)
			{
				if (temp % j == 0)
				{
					check[j] = check[temp / j] = true;
				}
			}
		}
	}
	if (flag)
	{
		cout << "0\n";
		return;
	}

	int tcnt = 0, ans = -1;
	for (int i = 2; i <= n; i++)
	{
		if (check[i] == false)
		{
			tcnt++;
			ans = i;
		}
	}
	if (tcnt == 0)
	{
		cout << 2 << "\n" << n - 1 << " " << n << "\n";
	}
	else cout << 1 << "\n" << ans << "\n";
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


