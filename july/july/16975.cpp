
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
ll getVal(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	return getVal(ptr * 2, s, mid, l, r) + getVal(ptr * 2 + 1, mid + 1, e, l, r);
}
void solve()
{
	int n; cin >> n;
	arr = vector<ll>(n + 10);
	segTree = vector<ll>(4 * (n + 10));

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		update(1, 1, n, i, arr[i] - arr[i - 1]);
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		if (x == 1)
		{
			int a, b, c; cin >> a >> b >> c;
			update(1, 1, n, a, c);
			update(1, 1, n, b + 1, -c);
		}
		else
		{
			int a; cin >> a;
			cout << getVal(1, 1, n, 1, a) << "\n";
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


