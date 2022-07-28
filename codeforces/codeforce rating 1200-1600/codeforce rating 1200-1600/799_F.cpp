
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
	vector<ll> cnt(10, 0);
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		cnt[x % 10]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (cnt[i])
		{
			cnt[i]--;
			for (int j = 0; j < 10; j++)
			{
				if (cnt[j])
				{
					cnt[j]--;
					for (int k = 0; k < 10; k++)
					{
						if (cnt[k])
						{
							if ((i + j + k) % 10 == 3)
							{
								cout << "YES\n";
								return;
							}
						}
					}
					cnt[j]++;
				}
				
			}
			cnt[i]++;
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


