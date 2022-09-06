
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

vector<ll> segTree;
vector<pll> lazy;
void setLazy(int ptr, int s, int e)
{
	if (lazy[ptr].first == 1 || lazy[ptr].second == 0)return;
	segTree[ptr] *= lazy[ptr].first;
	segTree[ptr] += (e - s + 1) * lazy[ptr].second;
	if (s != e)
	{
		lazy[ptr * 2].first *= lazy[ptr].first;
		lazy[ptr * 2].second = lazy[ptr].first * lazy[ptr * 2].second + lazy[ptr].second;
		lazy[ptr * 2 + 1].first *= lazy[ptr].first;
		lazy[ptr * 2 + 1].second = lazy[ptr].first * lazy[ptr * 2 + 1].second + lazy[ptr].second;
	}
	lazy[ptr].first = 1;
	lazy[ptr].second = 0;
}
void update(int ptr, int s, int e, int l, int r, ll val)
{
	setLazy(ptr, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r)
	{
		lazy[ptr].first = 0;
		lazy[ptr].second = val;
		setLazy(ptr, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, l, r, val);
	update(ptr * 2 + 1, mid + 1, e, l, r, val);
	segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}
ll query(int ptr, int s, int e, int l, int r)
{
	setLazy(ptr, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	return query(ptr * 2, s, mid, l, r) + query(ptr * 2 + 1, mid + 1, e, l, r);
}
void solve()
{
	int n, q; cin >> n >> q;
	segTree = vector<ll>(4 * n + 10);
	lazy = vector<pll>(4 * n + 10);

	for (int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		update(1, 1, n, i, i, x);
	}
	for (int i = 0; i < q; i++)
	{
		int op; cin >> op;
		if (op == 1)
		{
			ll a, b; cin >> a >> b;
			update(1, 1, n, a, a, b);
			cout << query(1, 1, n, 1, n) << "\n";
		}
		else
		{
			ll x; cin >> x;
			update(1, 1, n, 1, n, x);
			cout << query(1, 1, n, 1, n) << "\n";
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


