
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
	vector<int> neg, pos;
	bool zero = false;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x < 0) neg.push_back(x);
		if (x > 0) pos.push_back(x);
		if (x == 0) zero = true;
	}

	if (neg.size() > 2 || pos.size() > 2)
	{
		cout << "NO\n";
		return;
	}

	if ((neg.size() == 2 && pos.size() == 0) || (neg.size() == 0 && pos.size() == 2))
	{
		cout << "NO\n";
		return;
	}

	if ((neg.empty() && pos.empty()) || (neg.empty()&&pos.size()==1) || (neg.size()==1 && pos.empty()))
	{
		cout << "YES\n";
		return;
	}

	if ((neg.size() == 1) && (pos.size() == 1))
	{
		if (-neg[0] == pos[0])
		{
			cout << "YES\n";
			return;
		}
		else
		{
			cout << "NO\n";
			return;
		}
	}

	vector<int> v;
	for (auto u : neg) v.push_back(u);
	for (auto u : pos) v.push_back(u);
	if (zero) v.push_back(0);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				bool flag = false;
				for (int l = 0; l < v.size(); l++)
				{
					if (v[i] + v[j] + v[k] == v[l]) flag = true;
				}
				if (!flag)
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


