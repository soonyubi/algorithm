
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

ll n;
vector<ll> fact;
const ll INF = 1e12;
ll ans = 1e12;
void getFact()
{
	fact.push_back(6);
	for (ll i = 4; i < 15; i++)
	{
		ll temp = fact.back() * i;
		if (temp <= INF)
		{
			fact.push_back(temp);
		}
	}
	reverse(fact.begin(), fact.end());
	
}
int cnt_bit(ll x)
{
	int cnt = 0;
	for (ll i = 0; i < 44; i++)
	{
		if (x & (1ll << i)) cnt++;
	}
	return cnt;
}
void go(ll sum, ll cnt,int idx)
{
	if (sum > n) return;
	if (idx == fact.size())
	{
		if (sum <= n)
		{
			ll diff = n - sum;
			ans = min(ans, cnt + cnt_bit(diff));
		}
		return;
	}
	
	go(sum + fact[idx], cnt + 1, idx + 1);
	go(sum, cnt, idx + 1);
	
}
void solve()
{
	cin >> n;
	ans = INF;
	go(0, 0, 0);
	cout << ans << "\n";
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getFact();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


