
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

const int MAX = 1e5 + 11111;
const ll inf = 1e9 + 10;

pair<int, int> segTree[MAX * 4];

void update(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	if (s == e)
	{
		segTree[ptr].first = val;
		segTree[ptr].second = val;
		return;
	}
	int mid = (s + e) / 2;

	update(ptr * 2, s, mid, i, val);
	update(ptr * 2 + 1, mid + 1, e, i, val);

	segTree[ptr].first = min(segTree[ptr * 2].first, segTree[ptr * 2 + 1].first);
	segTree[ptr].second = max(segTree[ptr * 2].second, segTree[ptr * 2 + 1].second);
	
}
pair<ll, ll> getValue(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return{ inf,-inf };
	if (l <= s && e <= r)
	{
		return segTree[ptr];
	}
	int mid = (s + e) / 2;
	pair<ll, ll> tmp1 = getValue(ptr * 2, s, mid, l, r);
	pair<ll, ll> tmp2 = getValue(ptr * 2 + 1, mid + 1,e, l, r);
	pair<ll, ll> ret;
	ret.first = min(tmp1.first, tmp2.first);
	ret.second = max(tmp1.second, tmp2.second);
	return ret;
}
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		update(1, 1, n, i, x);
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b; cin >> a >> b;
		pair<ll, ll> ans = getValue(1, 1, n, a, b);
		cout << ans.first << " " << ans.second << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


