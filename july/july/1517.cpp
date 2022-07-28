
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

vector<pll> arr;
vector<ll> segTree;
void update(int ptr, int s, int e, int i, ll diff)
{
	if (s > i || e < i) return;
	segTree[ptr] += diff;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, diff);
	update(ptr * 2+1,mid+1,e, i, diff);
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
	int n; cin >> n;
	segTree = vector<ll>(4 * (n + 10));
	arr.push_back({ 0,0 });
	
	for (int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		arr.push_back({ x,i });
	}
	sort(arr.begin(), arr.end());
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ll x = arr[i].second;
		ans += query(1, 1, n, x + 1, n);
		update(1, 1, n, x, 1);
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


