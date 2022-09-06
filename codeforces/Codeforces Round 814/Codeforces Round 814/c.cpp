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

const int maxn = 1e5 + 1;
const ll INF = 1e9 + 7;
ll segTree[maxn * 4];

void update(int ptr, int s, int e, int i, ll value)
{
	if (s > i || e < i) return;
	if (s == e)
	{
		segTree[ptr] = value;
		return;
	}

	update(ptr * 2, s, (s + e) / 2, i, value);
	update(ptr * 2 + 1, (s + e) / 2 + 1, e, i, value);

	segTree[ptr] = max(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}
int getMax(int ptr, int s, int e, int l, int r)
{
	if (r < s || e < l) return -INF;
	if (l <= s && e <= r) return segTree[ptr];

	return max(getMax(ptr * 2, s, (s + e) / 2, l, r), getMax(ptr * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
bool comp(pll a, pll b)
{
	return a.first < b.first && a.second < b.second;
}
void solve()
{
	ll n, q; cin >> n >> q;
	vector<ll> v(n + 1);
	vector<ll> p(n + 1);
	vector<pll> vv;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i]; p[v[i]] = i;
		vv.push_back({ i,v[i] });
		update(1, 1, n, i, v[i]);
	}

	for (int i = 0; i < q; i++)
	{
		ll idx, k; cin >> idx >> k;
		if (v[idx] == n)
		{
			if (idx < 3)
			{
				cout << k << "\n";
			}
			else
			{
				k -= (idx - 2);
				if (k <= 0) cout << "0\n";
				else cout << k << "\n";
			}
		}
		else
		{
			ll left = getMax(1, 1, n, 1, idx - 1);
			ll ans = 0;

			if (left > v[idx])
			{
				cout << "0\n";
				continue;
			}
			if (idx >= 3)
			{
				ans++;
				k -= (idx - 2);
			}
			else if (idx == 2)
			{
				ans++;
				k -= 1;
			}
			if (k <= 0)
			{
				cout << ans << "\n";
				continue;
			}

			ll tar = upper_bound(vv.begin(), vv.end(), pii(idx, v[idx]), comp) - vv.begin();
			ll cnt = tar - idx - 1;
			
			if (cnt <= k)
			{
				cout << cnt + ans << "\n";
			}
			else
			{
				cout << k + ans << "\n";
			}

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