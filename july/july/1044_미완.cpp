
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

pair<ll, vector<ll>> cache[20][20];

void solve()
{
	int n; cin >> n;
	vector<ll> ans(n,0);
	ll ans_sum = LLONG_MAX;
	vector<int> brute(n);
	vector<ll> v1(n);
	vector<ll> v2(n);
	for (ll& x : v1) cin >> x;
	for (ll& x : v2) cin >> x;
	
	for (ll i = 0; i < (1ll << n / 2); i++)
	{
		
		ll cnt1 = 0;
		ll s1 = 0, s2 = 0;
		vector<ll> temp_ans(n,2);
		for (ll j = 0; j < n / 2; j++)
		{
			if (i & (1ll << j))
			{
				cnt1++;
				s1 += v1[j];
				temp_ans[j] = 1;
			}
			else
			{
				s2 += v2[j];
			}
		}
		// cache[cnt1][n/2-cnt1] // 만약 v1[0,n/2]에서 팀1로 2명을 선택했다면, v1[n/2,n]에서 팀1로 n/2-2 를 선택해야됌 
		ll cnt2 = 0;
		for (ll j = 0; j < n / 2; j++)
		{
			if (i & (1ll << j))
			{
				cnt2++;
				s1 += v1[j+n/2];
				temp_ans[j+n/2] = 1;
			}
			else
			{
				s2 += v2[j+n/2];
			}
		}
		for (auto u : temp_ans) cout << u << " "; cout << "\n";
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


