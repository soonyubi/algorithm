/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<ll, ll>
#define pll pair<ll, ll>
// ll_MAX ll_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

vector<ll> segTree;
vector<ll> arr;
void update(ll ptr, ll s, ll e, ll i, ll val)
{
	if (s > i || e < i) return;
	segTree[ptr] += val;
	if (s == e) return;
	ll mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, val);
	update(ptr * 2 + 1, mid + 1, e, i, val);
}
ll getSum(ll ptr, ll s, ll e, ll l, ll r)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return segTree[ptr];
	ll mid = (s + e) / 2;
	return getSum(ptr * 2, s, mid, l, r) + getSum(ptr * 2 + 1, mid + 1, e, l, r);
}
struct queryInfo
{
	ll query_num;
	ll idx;
	ll left;
	ll right;
};
vector<pll> change;
vector<queryInfo> query;
bool cmp(queryInfo q1, queryInfo q2)
{
	return q1.query_num < q2.query_num;
}
void solve()
{
	ll n; cin >> n;
	arr.resize(n + 10);
	segTree.resize(4 * (n + 10));
	for (ll i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		arr[i] = x;
		update(1, 1, n, i, x);
	}
	ll m; cin >> m;
	ll q2 = 0;
	for (ll i = 0; i < m; i++)
	{
		ll op; cin >> op;
		if (op == 1)
		{
			ll l, r; cin >> l >> r;
			change.push_back({ l,r });
		}
		if (op == 2)
		{
			ll qn, l, r; cin >> qn >> l >> r;
			queryInfo now; 
			now.idx = q2;
			now.left = l;
			now.right = r;
			now.query_num = qn;
			query.push_back(now);
			q2++;
		}
	}
	sort(query.begin(), query.end(), cmp);
	vector<ll> ans(q2);
	ll last = 0; ll idx = 0;
	for (auto u : query)
	{
		if (last != u.query_num)
		{

			last = u.query_num;
			auto cur = change[idx];
			ll i = cur.first;
			ll diff = cur.second - arr[i];
			arr[i] = cur.second;

			update(1, 1, n, i, diff);
			idx++;
		}
		ans[u.idx] = getSum(1, 1, n, u.left, u.right);
	}
	for (ll i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


