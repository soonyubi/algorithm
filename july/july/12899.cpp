
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

const int maxn = 2000000;
vector<ll> segTree;
void update(int ptr, int s, int e, int i, ll diff)
{
	if (s > i || e < i) return;
	segTree[ptr] += diff;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, diff);
	update(ptr * 2 + 1, mid + 1, e, i, diff);
}
ll query(int ptr, int s, int e, int k)
{
	segTree[ptr]--;
	if (s == e) return s;
	if (k <= segTree[ptr * 2])
	{
		return query(ptr * 2, s, (s + e) / 2, k);
	}
	else
	{
		return query(ptr * 2 + 1, (s + e) / 2 + 1, e, k - segTree[ptr*2]);
	
	}
}
void solve()
{
	int m; cin >> m;
	segTree = vector<ll>(maxn * 4 + 10);
	for (int i = 0; i < m; i++)
	{
		int op, x; cin >>op >>x;
		if (op == 1) update(1, 1, maxn, x, 1);
		else cout << query(1, 1, maxn, x) << "\n";
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


