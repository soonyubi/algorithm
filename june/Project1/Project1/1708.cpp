
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

vector<pll> v;
pll p2v(pll a, pll b)
{
	return { b.first - a.first,b.second - a.second };
}
ll ccw(pll v1, pll v2)
{
	ll res = v1.first * v2.second - v1.second * v2.first;
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}
ll dist2(pll a, pll b)
{
	ll dx = b.first - a.first;
	ll dy = b.second - a.second;
	return dx * dx + dy * dy;
}
bool cmp(pll a, pll b)
{
	pll v1 = p2v(v[0], a);
	pll v2 = p2v(v[0], b);

	ll res = ccw(v1, v2);
	if (res) return res > 0;
	// 일직선인 경우 길이가 짧은것
	return dist2(v[0], a) < dist2(v[0], b);
}
void solve()
{
	int n; cin >> n;
	v = vector<pll>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
		if (v[i] < v[0]) swap(v[i], v[0]);
	}

	sort(v.begin()+1, v.end(),cmp);

	vector<pll> CH;

	for (int i = 0; i < n; i++)
	{
		while (CH.size() > 1)
		{
			pll p1 = CH[CH.size() - 2];
			pll p2 = CH[CH.size() - 1];
			pll p3 = v[i];

			pll v1 = p2v(p1, p2);
			pll v2 = p2v(p2, p3);

			ll res = ccw(v1, v2);
			if (res > 0) break;
			CH.pop_back();
		}
		CH.push_back(v[i]);
	}
	cout << CH.size() << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


