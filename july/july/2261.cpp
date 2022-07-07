
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

vector<pll> point;

ll dist(pll a, pll b)
{
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}
bool cmp(pll a, pll b)
{
	return a.second < b.second;
}
ll go(int l, int r)
{
	if ((r - l + 1) <= 3)
	{
		ll ret = 1e9;
		for (int i = l; i <= r; i++)
		{
			for (int j = i + 1; j <= r; j++)
			{
				ret = min(ret, dist(point[i], point[j]));
			}
		}
		return ret;
	}

	int mid = (l + r) / 2;
	ll d1 = go(l, mid);
	ll d2 = go(mid + 1, r);
	ll d = min(d1, d2);

	vector<pll> tmp;
	for (int i = l; i <= r; i++)
	{
		ll dx = point[i].first - point[mid].first;
		if (dx * dx < d)
		{
			tmp.push_back(point[i]);
		}
	}

	sort(tmp.begin(), tmp.end(),cmp);

	for (int i = 0; i < tmp.size(); i++)
	{
		for (int j = i + 1; j < tmp.size(); j++)
		{
			ll dy = tmp[i].second - tmp[j].second;
			if (dy * dy < d)
			{
				d = min(d, dist(tmp[i], tmp[j]));
			}
			else break;
		}
	}

	return d;
}
void solve()
{
	int n; cin >> n;
	point = vector<pll>(n);
	for (auto& x : point) cin >> x.first >> x.second;

	sort(point.begin(),point.end());

	cout << go(0, n - 1) << "\n";

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


