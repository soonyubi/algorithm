
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
const ll maxn = 1e6;
void update(int ptr, int s, int e, int i, ll diff)
{
	if (s > i || e < i) return;
	segTree[ptr] += diff;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, diff);
	update(ptr * 2 + 1, mid + 1, e, i, diff);
}
ll query(int ptr, int s, int e, ll k)
{
	
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (segTree[ptr * 2] >= k)
	{
		return query(ptr * 2, s, mid, k);
	}
	else
	{
		return query(ptr * 2, mid + 1, e, k - segTree[ptr * 2]);
	}
}
void solve()
{
	segTree.resize(maxn * 4+ 11111);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int op; cin >> op;
		if (op == 1)
		{
			ll x; cin >> x;
			cout << query(1, 1, maxn, x) << "\n";
			update(1, 1, maxn, x, -1);
		}
		else
		{
			ll a, b; cin >> a >> b;
			update(1, 1, maxn, a, b);
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


