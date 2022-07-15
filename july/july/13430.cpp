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
vector<vector<ll>> matrix;
const ll mod = 1e9 + 7;
ll n, k;

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(k + 2, vector<ll>(k + 2));
	for (int i = 0; i < k + 2; i++)
	{
		for (int j = 0; j < k + 2; j++)
		{
			for (int l = 0; l < k + 2; l++)
			{
				ret[i][j] = (ret[i][j] + a[i][l] * b[l][j]) % mod;
			}
			ret[i][j] %= mod;
		}
	}
	return ret;

}
map < ll, vector<vector<ll>>> m;
vector<vector<ll>> pow(vector<vector<ll>> a, ll t)
{
	if (t == 1) return a;
	if (m.count(t)) return m[t];
	if (t % 2 == 1) return m[t] = mul(a, pow(a, t - 1));
	m[t / 2] = pow(a, t / 2);
	return mul(m[t / 2], m[t / 2]);
}

void solve()
{
	cin >> k >> n;
	
	matrix = vector<vector<ll>>(k + 2, (vector<ll>(k + 2)));
	for (int i = 0; i < k + 2; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			matrix[i][j] = 1;
		}
	}
	vector<vector<ll>> tmp = pow(matrix, n - 1);

	ll ans = 0;
	for (int i = 0; i < k + 2; i++)
	{
		ans = (ans + tmp[k + 1][i]) % mod;
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


