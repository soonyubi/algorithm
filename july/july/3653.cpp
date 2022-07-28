
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

vector<ll> arr;
vector<ll> segTree;

void update(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	segTree[ptr] += val;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, val);
	update(ptr * 2 + 1, mid + 1, e, i, val);

}

ll query(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	return query(ptr * 2, s, mid, l, r) + query(ptr * 2 + 1, mid + 1, e, l, r);
}
void solve()
{
	int n, m; cin >> n >> m;
	arr = vector<ll>(n + m + 10, 0);
	segTree = vector<ll>(4 * (n + m + 10), 0);
	

	for (int i = m + 1; i <= m + n; i++)
	{
		update(1, 1, n+m , i, 1);
		arr[i - m] = i;
	}

	int idx = m;
	for (int i = 0; i < m; i++)
	{
		int v; cin >> v;
		cout << query(1, 1, n + m, 1, arr[v] - 1) << " ";
		update(1, 1, n + m, arr[v], -1);
		arr[v] = idx--;
		update(1, 1, n + m, arr[v], 1);
	}
	cout << "\n";
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


