
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

pll p2v(pll p1, pll p2)
{
	return { p2.first - p1.first,p2.second - p1.second };
}
ll ccw(pll v1, pll v2)
{
	ll res = v1.first * v2.second - v1.second * v2.first;
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}
ll dist(pll p1, pll p2)
{
	ll dx = p2.first - p1.first;
	ll dy = p2.second - p1.second;
	return dx * dx + dy * dy;
}
bool cmp(pll p1, pll p2)
{
	pll v1 = p2v(point[0], p1);
	pll v2 = p2v(point[0], p2);
	ll res = ccw(v1, v2);

	if (res) return res > 0;
	return dist(point[0], p1) < dist(point[0], p2);
}
void solve()
{
	int n; cin >> n;
	point.clear();
	for (int i = 0; i < n; i++)
	{
		ll x, y, w; cin >> x >> y >> w;
		point.push_back({ x,y });
		point.push_back({ x+w,y });
		point.push_back({ x,y+w });
		point.push_back({ x+w,y+w });
	}
	for (int i = 1; i < 4 * n; i++)
	{
		if (point[0] > point[i])
		{
			swap(point[0], point[i]);
		}
	}
	sort(point.begin() + 1, point.end(), cmp);

	vector<pll> CH;
	for (int i = 0; i < 4 * n; i++)
	{
		while (CH.size() > 1)
		{
			pll p1 = CH[CH.size() - 2];
			pll p2 = CH[CH.size() - 1];
			pll p3 = point[i];

			pll v1 = p2v(p1, p2);
			pll v2 = p2v(p2, p3);
			ll res = ccw(v1, v2);
			if (res > 0) break;
			CH.pop_back();
		}
		CH.push_back(point[i]);
	}
	n = CH.size();
	int li = min_element(CH.begin(), CH.end()) - CH.begin();
	int ri = max_element(CH.begin(), CH.end()) - CH.begin();
	ll mxDist = 0;
	int ans1 = -1, ans2 = -1;

	for (int i = 0; i < n; i++)
	{
		pll p1 = CH[li];
		pll p1_nxt = CH[(li + 1) % n];
		pll p2 = CH[ri];
		pll p2_nxt = CH[(ri + 1) % n];

		ll curDist = dist(p1, p2);
		if (mxDist < curDist)
		{
			mxDist = curDist;
			ans1 = li, ans2 = ri;
		}

		pll v1 = p2v(p1, p1_nxt);
		pll v2 = p2v(p2_nxt, p2);
		if (ccw(v1, v2) > 0) li = (li + 1) % n;
		else ri = (ri + 1) % n;
	}
	cout << mxDist << "\n";
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


