
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


void update1(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	segTree[ptr] += val;
	if (s == e) return;
	int mid = (s + e) / 2;
	update1(ptr * 2, s, mid, i, val);
	update1(ptr * 2, mid + 1, e, i, val);
}
void update2(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	
	if (s == e) return;
	int mid = (s + e) / 2;
	update2(ptr * 2, s, mid, i, val);
	update2(ptr * 2, mid + 1, e, i, val);
}
ll query(int ptr, int s, int e, int l, int r, int k)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return segTree[ptr][k];
	int mid = (s + e) / 2;
	return query(ptr * 2, s, mid, l, r, k) + query(ptr * 2 + 1, mid + 1, e, l, r, k);
}
void solve()
{
	int n; cin >> n;
	segTree.resize(4 * n + 10);
	for (int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		update1(1, 1, n, i, x);
	}
	int m; cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		
		int op; cin >> op;
		if (op == 1)
		{
			ll a, v; cin >> a >> v;
			update2(1, 1, n, a, v);
		}
		else
		{
			ll k, l, r; cin >> k >> l >> r;
			cout << query(1, 1, n, l, r, k) << "\n";
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


