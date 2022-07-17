
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
	vector<ll> pos, neg;
	bool zero = false;
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		
		if (x < 0) neg.push_back(x);
		else if(x>0) pos.push_back(x);
		else zero = true;
	}

	if (neg.size() > 2 || pos.size() > 2)
	{
		cout << "NO\n";
		return;
	}

	vector<ll> v;
	if (zero) v.push_back(0);
	for (auto u : pos) v.push_back(u);
	for (auto u : neg) v.push_back(u);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				int cnt = 0;
				for (int l = 0; l < v.size(); l++)
				{
					if (v[i] + v[j] + v[k] == v[l]) cnt++;
				}
				if (cnt == 0)
				{
					cout << "NO\n";
					return;
				}
			}
		}
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


