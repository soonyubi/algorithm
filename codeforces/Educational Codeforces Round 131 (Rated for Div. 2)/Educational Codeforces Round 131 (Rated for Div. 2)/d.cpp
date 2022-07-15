
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
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	int d1 = a.second.second - a.second.first;
	int d2 = b.second.second - b.second.first;
	return d1 > d2;
}
void solve()
{
	int n; cin >> n;
	vector<int> b(n+1);
	vector<int> a(n+1);
	vector<bool> check(n + 1, false);
	vector<bool> idx(n + 1, false);
	vector<pair<int, pair<int, int>>> v;
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++)
	{
		
		int l = i / (b[i] + 1);
		int r;
		if (b[i] == 0) r = n;
		else r = i / b[i];
		// l< a[i] <= r
		if (r - l == 1)
		{
			a[i] = r;
			check[r] = true;
			idx[i] = true;
		}
		else
		{
			v.push_back({ i,{l + 1,r} });
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	while (!v.empty())
	{
		auto x = v.back(); v.pop_back();
		for (int i = x.second.first; i <= x.second.second; i++)
		{
			if (!check[i])
			{
				a[x.first] = i;
				check[i] = true;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}cout << "\n";
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


