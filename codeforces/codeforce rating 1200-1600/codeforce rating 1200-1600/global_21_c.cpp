
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
	int n, m; cin >> n >> m;
	vector<ll> v1(n);
	ll sum1 = 0, sum2 = 0;
	for (ll& x : v1) {
		cin >> x; sum1 += x;
	}
	int n2; cin >> n2;
	vector<ll> v2(n2);
	for (ll& x : v2) {
		cin >> x; sum2 += x;
	}
	if (sum1 != sum2)
	{
		cout << "NO\n";
		return;
	}
	vector<pll> ctg1,ctg2;

	for (int i = 0; i < n; i ++)
	{
		ll tmp = v1[i];
		ll cnt = 1;
		while (tmp % m == 0)
		{
			cnt *= m;
			tmp /= m;
		}
		if (ctg1.empty()) ctg1.push_back({ tmp,cnt });
		else
		{
			if (ctg1.back().first == tmp)
			{
				ctg1.back().second += cnt;
			}
			else
			{
				ctg1.push_back({ tmp,cnt });
			}
		}
	}

	for (int i = 0; i < n2; i++)
	{
		ll tmp = v2[i];
		ll cnt = 1;
		while (tmp % m == 0)
		{
			cnt *= m;
			tmp /= m;
		}
		if (ctg2.empty()) ctg2.push_back({ tmp,cnt });
		else
		{
			if (ctg2.back().first == tmp)
			{
				ctg2.back().second += cnt;
			}
			else
			{
				ctg2.push_back({ tmp,cnt });
			}
		}
	}

	if (ctg1.size() != ctg2.size())
	{
		cout << "NO\n"; return;
	}

	for (int i = 0; i < ctg1.size(); i++)
	{
		if (ctg1[i].first == ctg2[i].first)
		{
			if (ctg1[i].second != ctg2[i].second)
			{
				cout << "NO\n";
				return;
			}
		}
		else
		{
			cout << "NO\n";
			return;
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


