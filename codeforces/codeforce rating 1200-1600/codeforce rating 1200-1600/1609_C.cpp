
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

const int maxn = 1e6 + 1;
bool isP[maxn];

void era()
{
	memset(isP, true, sizeof(isP));
	isP[1] = false;
	for (int i = 2; i < maxn; i++)
	{
		if (!isP[i]) continue;
		for (int j = 2; j * i < maxn; j++)
		{
			isP[i * j] = false;
		}
	}
	
}

void solve()
{
	ll n, e; cin >> n >> e;
	vector<ll> left(n + 1), right(n + 1), v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = n; i >= 1; i--)
	{
		if (v[i] == 1)
		{
			if (i + e <= n) left[i] = left[i + e] + 1;
			else left[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 1)
		{
			if (i - e >= 1) right[i] = right[i - e] + 1;
			else right[i] = 1;
		}
	}

	//for (int i = 1; i <= n; i++) cout << left[i] << " "; cout << "\n";
	//for (int i = 1; i <= n; i++) cout << right[i] << " "; cout << "\n";
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isP[v[i]])
		{
			if (i - e >= 1) ans += right[i - e];
			if (i + e <= n) ans += left[i + e];
			if (i - e >= 1 && i + e <= n) ans += left[i + e] * right[i - e];
		}
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	era();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


