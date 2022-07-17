
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
vector<pll> segTree;
vector<ll> arr;
const ll inf = 1e9;
void update(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	if(s==e)
	{
		segTree[ptr] = { val,val };
		return;
	}
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, val);
	update(ptr * 2 + 1, mid + 1, e, i, val);
	segTree[ptr].first = max(segTree[ptr * 2].first, segTree[ptr * 2 + 1].first);
	segTree[ptr].second = min(segTree[ptr * 2].second, segTree[ptr * 2 + 1].second);
}
pll getVal(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return { -inf,inf };
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	pll t1 = getVal(ptr * 2, s, mid, l, r);
	pll t2 = getVal(ptr * 2 + 1, mid + 1, e, l, r);
	pll ret; 
	ret.first = max(t1.first, t2.first);
	ret.second = min(t1.second, t2.second);
	return ret;
}
void solve()
{
	int n, k; cin >> n >> k;
	segTree = vector<pll>(4 * (n + 10));
	arr = vector<ll>(n + 10);
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
		update(1, 1, n, i, arr[i]);
	}
	for (int i = 0; i < k; i++)
	{
		int op, a, b; cin >> op >> a >> b; a++, b++;
		if (op == 1)
		{
			auto ret = getVal(1, 1, n, a, b);
			if (a == ret.second && b == ret.first)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			update(1, 1, n, a, arr[b]);
			update(1, 1, n, b, arr[a]);
			ll temp = arr[b];
			arr[b] = arr[a];
			arr[a] = temp;
		}
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


