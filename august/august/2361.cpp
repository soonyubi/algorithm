
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii  pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld,ld>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }


pld ans;
const ld inf = 1e9;
ld mn = inf;
vector<pld> v;
int n;
vector<pair<pld,pld>> temp;
void go(ld x,ld y,ld l)
{
	if (l < 1e-6) return;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].first >= x && v[i].first <= x + l && v[i].second >= y && v[i].second <= y + l)
		{
			cnt++;
		}
	}

	//if (cnt <=0 ) return;
	if (cnt >= (n + 1) / 2)
	{
		if (mn > l)
		{
			mn = l;
			ans = { x,y };
		}
	}
	else temp.push_back({ {cnt,l},{ x,y } });
	ld nl = l / 4.0;
	go(x, y, nl);
	go(x + nl, y, nl);
	go(x, y + nl, nl);
	go(x + nl, y + nl, nl);

}
void solve()
{
	cin >> n;
	v.resize(n);
	 
	for (auto& u : v)
	{
		cin >> u.first >> u.second;
	}

	go(0.0, 0.0, 100015.0);
	
	cout << mn << "\n";
	cout << ans.first << " " << ans.second;

	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if (temp[i].first.first + temp[j].first.first < (n + 1) / 2) continue;
			ld s = min(temp[i].second.first, temp[j].second.first);
			ld e = max(temp[i].second.first + temp[i].first.second, temp[j].second.first + temp[j].first.second);
			pld st = { s,s };
			pld ed = { e,e };
			if (mn > e-s)
			{
				mn = e - s;
				ans = st;
			}
		}
	}


	cout << fixed;
	cout.precision(6);
	cout << mn << "\n";
	cout << ans.first << " " << ans.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


