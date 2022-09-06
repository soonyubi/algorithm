
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
	int n, a, b;
	cin >> n >> a >> b;
	if (n == 2)
	{
		if (a > 0 || b > 0) cout << "-1\n";
		else
		{
			cout << "1 2\n";
		}
		return;
	}
	if (a + b > n - 2 || abs(a-b)>1)
	{
		cout << "-1\n";
		return;
	}
	vector<int> ans(n + 1);
	if (a == b)
	{
		int k = 1;
		for (int i = 0; i < a; i++)
		{
			ans[2 + 2 * i] = k++;
		}
		k = n;
		for (int i = 1; i <= n; i++)
		{
			if (ans[i] == 0)
			{
				ans[i] = k--;
			}
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";

	}
	else
	{
		// a-b = 1 or b-a=1
		if(a>b)
		{ 
			ans[1] = 1;
			int k = 2;
			for (int i = 0; i < b; i++) ans[3 + 2 * i] = k++;
			k = n;
			for (int i = 1; i <= n; i++)
			{
				if (ans[i] == 0)
				{
					ans[i] = k--;
				}
			}
		}
		else
		{
			int k = 1;
			for (int i = 0; i < b; i++) ans[2 + 2 * i] = k++;
			k = n;
			for (int i = n; i >=1; i--)
			{
				if (ans[i] == 0)
				{
					ans[i] = k--;
				}
			}
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
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


