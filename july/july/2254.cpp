
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pll  pair<int, int>
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
pll p2v(pll a, pll b)
{
	return { b.first - a.first, b.second - a.second };
}
ll ccw(pll v1, pll v2)
{
	ll res = v1.first * v2.second - v2.first * v1.second;
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}
bool cmp(pll a, pll b)
{
	
	pll v1 = p2v(point[0], a);
	pll v2 = p2v(point[0], b);
	ll res = ccw(v1, v2);

	if (res) return res > 0;
	return dist(point[0], a) < dist(point[0], b);
}
bool cmp2(pll a, pll b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
bool isInside(vector <pll>& CH, pll point)
{
	int n = CH.size();

	pll vec_l = p2v(CH[0], CH[n - 1]);
	pll vec_r = p2v(CH[0], CH[1]);

	pll vec_c = p2v(CH[0], point);

	if (ccw(vec_l, vec_c) > 0) return false;
	if (ccw(vec_r, vec_c) < 0) return false;

	int l = 1, r = n - 1;
	while (l + 1 < r) // 이분탐색으로 점이 있는 구간을 찾는다
	{
		int m = (l + r) / 2;

		pll vec_m = p2v(CH[0], CH[m]);
		if (ccw(vec_m, vec_c) > 0) l = m;
		else r = m;
	}

	pll v1 = p2v(CH[l], point);
	pll v2 = p2v(point, CH[l + 1]);

	return ccw(v1, v2) < 0;
}
void solve()
{
	int n; cin >> n;
	pll cage; cin >> cage.first >> cage.second;
	point = vector<pll>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> point[i].first >> point[i].second;
	}

	int ans = 0;
	while (true)
	{
		if (point.size() < 3) break;
		
		sort(point.begin(), point.end(),cmp2); // y좌표 작은순 정렬
		sort(point.begin()+1, point.end(), cmp); // 각도별 정렬
		

		// 1. 볼록 다각형 생성
		vector<pll> CH;

		for (int i = 0; i < point.size(); i++)
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
		
		//2. 내부에 점 있는지 확인
		if (isInside(CH, cage)) ans++;
		else break;

		for (auto& u : CH)
		{
			point.erase(find(point.begin(), point.end(), u));
		}

		CH.clear();
	}
	
	cout << ans << "\n";
	


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


