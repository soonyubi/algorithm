
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
int cnt[maxn]; // 약수개수
int mn[maxn]; // 최소약수 (prime) 일경우 1
bool isP[maxn];
int TC = 1;
void era()
{
	memset(mn, maxn, sizeof(mn));
	memset(isP, true, sizeof(isP));

	for (int i = 2; i < maxn; i++)
	{
		//if (!isP[i]) continue;
		for (int j = 2; j*i < maxn; j++)
		{
			isP[i*j] = false;
			cnt[i * j]++;
			mn[i * j] = min(mn[i * j], i);
		}
	}
}

void solve()
{
	int n, m; cin >> n >> m;

	int div = cnt[n];
	int ans = 0;
	for (int i = 2; i < n; i++)
	{
		if (isP[i]) continue;
		if (div == cnt[i] && mn[i]>=m) 
		{
			ans++;
		}
	}
	cout << "Case #" << TC << ": " << ans << "\n";
	TC++;
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


