
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
const ll mod = 1e9 + 7;
ll dp[101];
ll n, m;

vector<vector<ll>> mulMtx(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(m + 1, vector<ll>(m + 1, 0));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}
vector<vector<ll>> powMtx(vector<vector<ll>> a, ll k)
{
	if (k == 1) return a;
	else if (k % 2 == 1) return mulMtx(a, powMtx(a, k - 1));
	vector<vector<ll>> tmp = powMtx(a, k / 2);
	return mulMtx(tmp, tmp);
}
void solve()
{
	 cin >> n >> m;
	dp[1] = 1; dp[m] = 1;
	for (int i = 2; i <= 100; i++)
	{
		dp[i] += dp[i - 1];
		if (i - m >= 0) dp[i] += dp[i - m];
		dp[i] %= mod;
	}
	if (n <= 100)
	{
		cout << dp[n]%mod << "\n";
		return;
	}

	vector<vector<ll>> matrix(m + 1, vector<ll>(m + 1, 0));
	matrix[1][1] = matrix[1][m] = 1;
	for (int i = 2; i <= m; i++)
	{
		matrix[i][i - 1] = 1;
	}
	
	vector<vector<ll>> A = powMtx(matrix, n - m);
	reverse(dp + 1, dp + m + 1);
	ll ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ans += (A[1][i] * dp[i]);
		ans %= mod;
	}
	cout << ans << "\n";
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


