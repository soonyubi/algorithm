
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
double angle(pll v1, pll v2)
{
	double inner = v1.first * v2.first + v1.second * v2.second;
	double cos = inner * inner;
	double s1 = dist(v1, { 0,0 });
	double s2 = dist(v2, { 0,0 });
	cos /= s1; cos /= s2;
	return cos;
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
	sort(point.begin() + 1, point.end(),cmp);

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
	

	int i1 = min_element(CH.begin(), CH.end()) - CH.begin();
	int i2 = max_element(CH.begin(), CH.end()) - CH.begin();

	ll mxDist = 0;
	int ans1 = -1, ans2 = -1;

	for (int i = 0; i < CH.size(); i++)
	{
		pll p1 = CH[i1];
		pll p1_nxt = CH[(i1 + 1) % CH.size()];
		pll p2 = CH[i2];
		pll p2_nxt = CH[(i2 + 1) % CH.size()];

		ll curDist = dist(p1, p2);
		if (curDist > mxDist)
		{
			mxDist = curDist;
			ans1 = i1, ans2 = i2;
		}
		
		pll v1 = p2v(p1, p1_nxt);
		pll v2 = p2v(p2_nxt, p2);
		// 외적으로 각도비교 
		//if (ccw(v1, v2) > 0) i1 = (i1 + 1) % CH.size();
		//else i2 = (i2 + 1) % CH.size();

		// 내적으로 각도비교
		
	}

	cout << CH[ans1].first << " " << CH[ans1].second << " " << CH[ans2].first << " " << CH[ans2].second << "\n";

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


