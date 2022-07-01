
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
bool cmp(pii a, pii b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
void solve()
{
	int n; cin >> n;
	vector<pii>v(n);
	for (auto& x : v)
	{
		cin >> x.first >> x.second;
		if (x.first > x.second) swap(x.first, x.second);
	}
	int d; cin >> d;
	sort(v.begin(), v.end(), cmp);
	priority_queue<int> pq;
	int ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		pq.push(-v[i].first);
		while (!pq.empty() && -pq.top() < (v[i].second - d)) pq.pop();
		ans = max(ans, (int)pq.size());
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


