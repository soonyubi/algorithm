
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
	vector<int> red, blue, v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		if (c == 'R') red.push_back(v[i]);
		else blue.push_back(v[i]);
	}

	sort(red.begin(), red.end()); reverse(red.begin(), red.end());
	sort(blue.begin(), blue.end()); reverse(blue.begin(), blue.end());

	int k = n;
	for (int i = 0; i < red.size(); i++)
	{
		if (red[i] > k)
		{
			cout << "NO\n";
			return;
		}
		k--;
	}
	for (int i = 0; i < blue.size(); i++)
	{
		if (blue[i] < k)
		{
			cout << "NO\n";
			return;
		}
		k--;
	}
	cout << "YES\n";
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


