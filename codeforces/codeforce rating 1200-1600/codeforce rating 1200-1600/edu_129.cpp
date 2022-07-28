
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
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	vector<pii> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
				swap(b[i], b[j]);
				ans.push_back({ i + 1,j + 1 });
			}
			else if (a[i] == a[j])
			{
				if (b[i] < b[j])
				{
					swap(b[i], b[j]);
					ans.push_back({ i + 1,j + 1 });
				}
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (b[i] <= b[i + 1]) continue;
		else
		{
			cout << "-1\n";
			return;
		}
	}
	cout << ans.size() << "\n";
	for (auto u : ans)
	{
		cout << u.first << " " << u.second << "\n";
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


