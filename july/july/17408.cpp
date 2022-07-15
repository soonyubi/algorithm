
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

vector<pii> segTree;
void update(int ptr, int s, int e, int i, int val)
{
	if (s > i || e < i) return;
	if (s == e)
	{
		segTree[ptr] = { s,val };
		return;
	}
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, val);
	update(ptr * 2 +1 , mid +1, e, i, val);
	if (segTree[ptr * 2].second < segTree[ptr * 2 + 1].second) segTree[ptr] = segTree[ptr * 2 + 1];
	else segTree[ptr] = segTree[ptr * 2];
}
pii getVal(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return { -1,0 };
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	pii t1 = getVal(ptr * 2, s, mid, l, r);
	pii t2 = getVal(ptr * 2 + 1, mid + 1, e, l, r);
	if (t1.second > t2.second) return t1;
	else return t2;
}
void solve()
{
	int n; cin >> n;
	segTree.resize(4 * (n + 10));
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		update(1, 1, n, i, x);
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int op; cin >> op; 
		if (op == 1)
		{
			int a, b; cin >> a >> b;
			update(1, 1, n, a, b);
		}
		else
		{
			int a, b; cin >> a >> b;
			pii t1 = getVal(1, 1, n, a, b);
			pii t2 = getVal(1, 1, n, a, t1.first - 1);
			pii t3 = getVal(1, 1, n, t1.first + 1, b);
			cout << max(t1.second + t2.second, t1.second + t3.second) << "\n";
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


