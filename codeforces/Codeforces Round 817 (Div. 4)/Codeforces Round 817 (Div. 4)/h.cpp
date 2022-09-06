
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
const ll maxn = (1ll << 31ll) - 1;
void solve()
{
	ll n; cin >> n;
	vector<ll> ans(n,0);
	if (n == 3)
	{
		cout << "2 1 3\n";
		return;
	}
	if (n % 4 == 0 )
	{
		ll k = 1;
		for (int i = 0; i < n; i += 4)
		{
			ans[i] = k; ans[i + 2] = maxn ^ k; k++;
		}
		for (int i = 1; i < n; i += 4)
		{
			ans[i] = k; ans[i + 2] = maxn ^ k; k++;
		}
	}
	else if (n % 4 == 1)
	{
		ll k = 1;
		for (int i = 0; i < n-1; i += 4)
		{
			ans[i] = k; ans[i + 2] = maxn ^ k; k++;
		}
		for (int i = 1; i < n-1; i += 4)
		{
			ans[i] = k; ans[i + 2] = maxn ^ k; k++;
		}
	}
	else if(n%4==2)
	{
		ll k = 1;
		ans[0] = 4; ans[2] = 2; ans[4] = 3;
		k = 3;
		ans[1] = 1; ans[3] = 12; ans[5] = 8;
		k = 13;
		for (int i = 0; i < (n - 6); i += 4)
		{
			ans[i + 6] = k; ans[i + 8] = maxn ^ k; k++;
		}
		for (int i = 1; i < (n - 6); i += 4)
		{
			ans[i + 6] = k; ans[i + 8] = maxn ^ k; k++;
		}
	}
	else
	{
		ll k = 1;
		ans[0] = 4; ans[2] = 2; ans[4] = 3;
		k = 3;
		ans[1] = 1; ans[3] = 12; ans[5] = 8;
		k = 13;
		for (int i = 0; i < (n - 6)-1; i += 4)
		{
			ans[i + 6] = k; ans[i + 8] = maxn ^ k; k++;
		}
		for (int i = 1; i < (n - 6)-1; i += 4)
		{
			ans[i + 6] = k; ans[i + 8] = maxn ^ k; k++;
		}
	}
	for (auto u : ans) cout << u << " "; cout << "\n";
	/*
	ll odd = 0;
	ll even = 0;
	
	for (int i = 0; i < n; i++)
	{
		
		if (i % 2 == 0) even ^= ans[i];
		if (i % 2 == 1) odd ^= ans[i];
	}
	if (even == odd) {
		cout << even << "\n";
		cout << "YES\n";
	}*/
	
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


