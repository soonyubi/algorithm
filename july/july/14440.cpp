
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

const ll mod = 1e6;
vector<vector<ll>> matrix;
vector<vector<ll>> matrixMul(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(2, vector<ll>(2, 0));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}
vector<vector<ll>> matrixPow(vector<vector<ll>> a, ll k)
{
	if (k == 0) return { {1,0},{0,1} };
	if (k == 1) return a;
	if (k % 2 == 1) return matrixMul(a, matrixPow(a, k - 1));
	vector<vector<ll>> tmp = matrixPow(a, k / 2);
	return matrixMul(tmp, tmp);

}


void solve()
{
	ll n; cin >> n;

	matrix = vector<vector<ll>>(2, vector<ll>(2, 0));
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][0] = 1;
	matrix[1][1] = 0;

	if (n == 0) {
		cout << 0 << "\n"; return;
	}
	
	vector<vector<ll>> ret = matrixPow(matrix, n-1);

	ll ans = (ret[0][0] * 1 + ret[0][0] * 0);
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


