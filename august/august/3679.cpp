
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
	else if (res < 0)return -1;
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
	point = vector<pll>(n);
	map<pii, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		point[i] = { x,y };
		if (point[0].second > point[i].second) swap(point[0], point[i]);
		mp[{x, y}] = i;
	}
	sort(point.begin() + 1, point.end(), cmp);

	vector<pll> CH;

	pll v = p2v(point[0], point[n - 1]);
	int idx = -1;
	for (int i = n - 2; i > 0; i--)
	{
		pll temp = p2v(point[0], point[i]);
		ll res = ccw(v, temp);
		if (res == 0) CH.push_back(point[i]);
		else
		{
			idx = i;
			break;
		}
	}
	if (idx == n - 2 || idx==-1)
	{
		CH.clear();
		for (int i = 0; i < n; i++)
		{
			
			CH.push_back(point[i]);
		}
		for (auto u : CH)
		{
			cout << mp[u] << " ";
		}cout << "\n";
	}
	else
	{
		CH.push_back(point[n - 1]);
		CH.push_back(point[0]);
		for (int i = 0; i < CH.size(); i++)
		{
			if (CH[i] == point[0])
			{
				swap(CH[0], CH[i]);
				break;
			}
		}
		sort(CH.begin() + 1, CH.end(), cmp);
		reverse(CH.begin(), CH.end());

		for (int i = 1; i <= idx; i++)
		{
			
			CH.push_back(point[i]);
		}
		for (auto u : CH)
		{
			cout << mp[u] << " ";
		}cout << "\n";
	}

	
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


