
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

	// lazy[ptr] 값을 처리해준다. 
	segTree[ptr] += (e - s + 1) * val;
	
	// 리프노드가 아니라면 자식으로 propagation
	if (s != e)
	{
		lazy[ptr * 2] += val;
		lazy[ptr * 2 + 1] += val;
	}
}
void update(int ptr, int s, int e, int l, int r, ll val)
{
	// lazy tree 에 있는 값 먼저 처리
	if (lazy[ptr]) setLazy(ptr, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r)
	{
		segTree[ptr] += (e - s + 1) * val;

		if (s != e)
		{
			// 리프노드가 아니면 lazy 자식의 값에 propagation
			lazy[ptr * 2] += val;
			lazy[ptr * 2 + 1] += val;
		}

		return;
	}
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, l, r, val);
	update(ptr * 2 + 1, mid + 1, e, l, r, val);
	segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}

ll getVal(int ptr, int s, int e, int l, int r)
{
	if (lazy[ptr]) setLazy(ptr, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	return getVal(ptr * 2, s, mid, l, r) + getVal(ptr * 2 + 1, mid + 1, e, l, r);
}
void solve()
{
	int n, m, k; cin >> n >> m >> k;
	segTree = vector<ll>(4 * (n + 10));
	lazy = vector<ll>(4 * (n + 10));
	for (int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		update(1, 1, n, i, i, x);
	}
	for (int i = 0; i < m + k; i++)
	{
		int op; cin >> op;
		if (op == 1)
		{
			ll a, b, c; cin >> a >> b >> c;
			update(1, 1, n, a, b, c);
		}
		else
		{
			ll a, b; cin >> a >> b;
			cout << getVal(1, 1, n, a, b) << "\n";
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


