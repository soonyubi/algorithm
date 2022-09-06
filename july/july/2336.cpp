
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
struct test
{
	int x, y, z;
};
const ll inf = 1e9;
vector<test> arr;
vector<ll> segTree;
bool cmp(test a, test b)
{
	return a.x < b.x;
}
void update(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	if (s == e)
	{
		segTree[ptr] = val;
		return;
	}
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, val);
	update(ptr * 2 + 1, mid + 1, e, i, val);
	segTree[ptr] = min(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

ll query(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return inf;
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	return min(query(ptr * 2, s, mid, l, r), query(ptr * 2 + 1, mid + 1, e, l, r));
}
void solve()
{
	int n; cin >> n;
	arr = vector<test>(n + 1);
	segTree = vector<ll>(4 * (n + 10), inf);
	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		arr[t].x = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		arr[t].y = i;
	}for (int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		arr[t].z = i;
	}
	sort(arr.begin() + 1, arr.end(), cmp);
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i].x << " ";
	}cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i].y << " ";
	}cout << "\n"; for (int i = 1; i <= n; i++)
	{
		cout << arr[i].z << " ";
	}cout << "\n";
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ll ret = query(1, 1, n, 1, arr[i].y);
		if (ret > arr[i].z) ans++;
		
		update(1, 1, n, arr[i].y, arr[i].z);
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


