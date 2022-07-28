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
const int maxn = 1e6;
bool isPrime[maxn + 1];

map<ll, ll> cnt[101];
map<ll, ll> cnt2;

vector<ll> prime;
void getPrime()
{
	memset(isPrime, true, sizeof(isPrime));

	for (int i = 2; i <= maxn; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = 2; j <= maxn / i; j++)
		{
			isPrime[i * j] = false;
		}
	}
	for (ll i = 2; i <= maxn; i++) if (isPrime[i]) prime.push_back(i);
}
void getFact(ll x, int idx)
{
	
	for (auto u : prime)
	{
		while (x%u==0)
		{
			x /= u;
			cnt[idx][u]++;
		}
		if(cnt[idx][u]) cnt2[u] += cnt[idx][u];
	}
	
}
ll power(ll x, ll y) {
	ll res = 1;
	while (y > 0) {
		if (y % 2 == 1) {
			res = res * x;
		}
		y /= 2;
		x = x * x;
	}
	return res;
}
void solve()
{
	getPrime();
	int n; cin >> n;
	vector<ll> v(n);
	for (ll& x : v) cin >> x;

	for (int i = 0; i < n; i++)
	{
		getFact(v[i], i);
	}
	ll ans = 1;
	for (auto u : cnt2)
	{
		u.second = u.second / n;
		ans *= power(u.first, u.second);
	}
	
	cout << ans << " ";
	ll move = 0;
	for (int i = 0; i < n; i++)
	{
		for (auto u : cnt2)
		{
			if (cnt[i].count(u.first) != 0)
			{
				if (u.second > cnt[i][u.first])
				{
					move += u.second - cnt[i][u.first];
				}
			}
			else
			{
				move += u.second;
			}
		}
		
	}
	cout << move << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


