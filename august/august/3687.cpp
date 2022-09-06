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
string dp[111];

void getDP()
{

	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "0";
	dp[7] = "8";

	for (int i = 8; i < 101; i++)
	{
		int sz = i;
		for (int j = 2; j <= sz - 2; j++)
		{
			string a = dp[j];
			string b = dp[i - j];
			if (a[0] == '0') a = "6";
			string c = a + b;
			if (dp[i].empty()) dp[i] = c;
			else if (dp[i].size() >= c.size())
			{
				if (dp[i].size() == c.size()) dp[i] = min(dp[i], c);
				else
				{
					dp[i] = c;
				}
			}
		}
	}

}
void solve()
{
	int n; cin >> n;
	if (n == 6)
	{
		cout << "6 111\n";
		return;
	}
	string mx;
	if (n % 2 == 0)
	{
		for (int i = 0; i < n / 2; i++) mx.push_back('1');
	}
	else
	{
		mx.push_back('7');
		for (int i = 0; i < (n - 3) / 2; i++) mx.push_back('1');

	}
	
	cout << dp[n] << " " << mx << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getDP();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


