
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
vector<ll> lazy;

void setLazy(int ptr, int s, int e)
{
	ll val = lazy[ptr];
	lazy[ptr] = 0;

	segTree[ptr] += (e - s + 1)*val;

	if (s != e)
	{
		lazy[ptr * 2] += val;
		lazy[ptr * 2 + 1] += val;
	}
}
void update(int ptr, int s, int e, int l, int r, ll val)
{
	if (lazy[ptr]) setLazy(ptr, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r)
	{
		segTree[ptr] += (e - s + 1) * val;

		if (s != e)
		{
			lazy[ptr * 2] += val;
			lazy[ptr * 2 + 1] += val;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, l, r, val);
	update(ptr * 2+1, mid+1, e, l, r, val);
	segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}
ll query(int ptr, int s, int e, int l, int r)
{
	if (lazy[ptr]) setLazy(ptr, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	return query(ptr * 2, s, mid, l, r) + query(ptr * 2 + 1, mid + 1, e, l, r);
}
void solve()
{
	int n; cin >> n;
	segTree = vector<ll>(4 * (n + 10));
	lazy = vector<ll>(4 * (n + 10));

	ll last = 0;
	for (int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		update(1, 1, n, i, i, x - last);
		last = x;
	}

	int q; cin >> q;
	while (q--)
	{
		int op; cin >> op;
		if (op == 1)
		{
			ll a, b; cin >> a >> b;
			update(1, 1, n, a, b, 1);
			update(1, 1, n, b + 1, b+1, -(b-a+1));
		}
		else
		{
			ll a; cin >> a;
			cout << query(1, 1, n, 1, a) << "\n";
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


