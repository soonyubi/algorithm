
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

vector<ll> arr;
vector<ll> segTree;
const ll MOD = 1e9 + 7;

void update(int ptr, int s, int e, int i, ll value)
{
	if (s > i || e < i) return;
	if (s == e)
	{
		segTree[ptr] = value;
		return;
	}
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, value);
	update(ptr * 2 + 1, mid + 1, e, i, value);
	segTree[ptr] = (segTree[ptr * 2] * segTree[ptr * 2 + 1])%MOD;
}
ll getValue(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return -1;
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	ll left = getValue(ptr * 2, s, mid, l, r);
	ll right = getValue(ptr * 2 + 1, mid + 1, e, l, r);
	if (left < 0) return right %MOD;
	else if (right < 0) return left%MOD;
	else
	{
		return (left * right) % MOD;
	}
}

void solve()
{
	int n, m, k; cin >> n >> m >> k;
	int q = m + k;

	arr = vector<ll>(n + 10);
	segTree = vector<ll>(4 * (n + 10));
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		update(1, 1, n, i, arr[i]);
	}


	for (int i = 0; i < q; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, 1, n, b, c);
		}
		else
		{
			cout << getValue(1, 1, n, b, c) << "\n";
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


