
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
int n, S, E, t;
const ll mod = 1e6 + 3;

vector<vector<ll>> mulMtx(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(n * 5 + 1, vector<ll>(n * 5 + 1, 0));

	for (int i = 1; i <= 5 * n; i++)
	{
		for (int j = 1; j <= 5 * n; j++)
		{
			for (int k = 1; k <= 5 * n; k++)
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
	if (k % 2 == 1) return mulMtx(a, powMtx(a, k - 1));
	vector<vector<ll>> temp = powMtx(a, k / 2);
	return mulMtx(temp, temp);
}

void solve()
{
	cin >> n >> S >> E >> t;
	vector<vector<ll>> matrix(n * 5 + 1, vector<ll>(n * 5 + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c; cin >> c; int cost = c - '0'; 
			if (cost > 0)
			{
				matrix[i * 5][j * 5 - (cost - 1)] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			//cout << (i - 1) * 5 + j << " -> " << (i - 1) * 5 + j + 1 << "\n";
			matrix[(i - 1) * 5 + j][(i - 1) * 5 + j + 1] = 1;
		}
	}
	
	vector<vector<ll>> ans = powMtx(matrix, t);
	
	cout << ans[S * 5][E * 5] << "\n";

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


