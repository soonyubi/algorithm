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
	return { p2.first - p1.first, p2.second - p1.second };
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
bool cmp(pll a, pll b)
{
	pll v1 = p2v(point[0], a);
	pll v2 = p2v(point[0], b);

	ll res = ccw(v1, v2);
	if (res) return res > 0;
	return dist(point[0], a) < dist(point[0], b);
}
ll inner(pll v1, pll v2)
{
	ll inner = v1.first * v2.first + v1.second * v2.second;
	
	return inner;
}
void solve()
{
	int n; cin >> n;
	point = vector<pll>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> point[i].first >> point[i].second;
		if (point[0] > point[i]) swap(point[0], point[i]);
	}

	// point[0]를 기준으로 각도별 정렬
	sort(point.begin() + 1, point.end(), cmp);

	vector<pll> CH;

	for (int i = 0; i < n; i++)
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


	// rotating calipers
	int pl = 0; int pr = 0;
	
	for (int i = 0; i < CH.size(); i++)
	{
		if (CH[pl].first > CH[i].first) pl = i;
		if (CH[pr].first < CH[i].first) pr = i;
	}
	n = CH.size();
	// calipers를 y축에 평행하게 설정
	pll calipers = { 0,1 };
	pll ans = { pl,pr };
	ll d = dist(CH[pl], CH[pr]);
	for (int i = 0; i < n; i++)
	{
		ll inner1 = inner(calipers, p2v(CH[(pl+1)%n], CH[pl]));
		ll inner2 = inner(calipers, p2v(CH[pr], CH[(pr + 1)%n]));

		double cosl = inner1 / dist(CH[(pl + 1) % n], CH[pl]); cosl /= dist({ 0,0 }, calipers);
	}
	cout << CH[ans.first].first << " " << CH[ans.first].second << " " << CH[ans.second].first << " " << CH[ans.second].second << "\n";

	
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


