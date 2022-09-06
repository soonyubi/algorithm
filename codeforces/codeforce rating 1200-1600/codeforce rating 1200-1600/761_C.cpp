
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
	vector<bool> check(n + 1, false);
	set<int> stk;
	vector<int> v;
	for (int i = 1; i <= n; i++) stk.insert(i);
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (stk.find(x) != stk.end()) { stk.erase(x); }
		else v.push_back(x);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		auto it = stk.end(); it--;
		int tar = (*it);
		if (tar * 2 + 1 <= v[i])
		{
			stk.erase(tar);
		}
		else
		{
			cout << "-1\n";
			return;
		}
	}
	cout << v.size() << "\n";
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


