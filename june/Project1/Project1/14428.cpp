
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

vector<pair<ll,ll>> segTree;
const int inf = 1e9+90;
void update(int ptr, int s, int e, int i, ll value)
{
	if (s > i || e < i) return;
	if (s == e)
	{
		segTree[ptr] = {value,i};
		return;
	}
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, value);
	update(ptr * 2 + 1, mid + 1, e, i, value);
	if (segTree[ptr * 2].first < segTree[ptr * 2 + 1].first)
	{
		segTree[ptr] = segTree[ptr * 2];
	}
	else if (segTree[ptr * 2].first > segTree[ptr * 2 + 1].first)
	{
		segTree[ptr] = segTree[ptr * 2 + 1];
	}
	else
	{
		if (segTree[ptr * 2].second < segTree[ptr * 2 + 1].second)
		{
			segTree[ptr] = segTree[ptr * 2];
		}
		else
		{
			segTree[ptr] = segTree[ptr * 2 + 1];
		}
	}
}

pair<ll,ll> getIdx(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return {inf,-1};
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	auto left = getIdx(ptr * 2, s, mid, l, r);
	auto right = getIdx(ptr * 2 + 1, mid + 1, e, l, r);
	if (left.first < right.first)
	{
		return left;
	}
	else if (left.first > right.first)
	{
		return right;
	}
	else
	{
		if (left.second < right.second)
		{
			return left;
		}
		else return right;
	}
}
void solve()
{
	int n; cin >> n;
	segTree = vector<pair<ll, ll>>(4 * (n + 10));

	for (int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		update(1, 1, n, i, x);
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, 1, n, b, c);
		}
		else
		{
			if (b > c) swap(b, c);
			cout << getIdx(1, 1, n, b, c).second <<"\n";
		}
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


