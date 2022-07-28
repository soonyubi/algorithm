
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

const ll maxn = 200000;
vector<pll> segTree(4*(maxn+10));
const ll mod = 1e9 + 7;

void update(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	segTree[ptr].first++;
	segTree[ptr].second += val;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, val);
	update(ptr * 2+1, mid +1 , e, i, val);
}
pll query(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return { 0,0 };
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	pll t1 = query(ptr * 2, s, mid, l, r);
	pll t2 = query(ptr * 2 + 1, mid + 1, e, l, r);
	pll ret = { t1.first + t2.first , t1.second + t2.second };
	return ret;
}
ll MOD(ll a)
{
	return a % mod;
}
void solve()
{
	int n; cin >> n;
	//segTree = vector<pll>(4 * (n + 10));
	ll ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		if (i == 1)
		{
			update(1, 0, maxn, x, x);
			continue;
		}
		pll left = query(1, 0, maxn, 0, x - 1);
		pll right = query(1, 0, maxn, x + 1, maxn);
		ll left_res = x * left.first - left.second;
		ll right_res = right.second - x * right.first;
		left_res %= mod;
		right_res %= mod;
		
		ll res = (left_res + right_res) % mod;
		
		ans = ans * res;
		ans %= mod;
		
		update(1, 0, maxn, x, x);
	}
	cout << ans%mod << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


