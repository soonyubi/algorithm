
/*
*   Time :
*   Subject : dp(행렬) +  가중치 없는 행렬의 거듭제곱
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
vector<vector<ll>> mulMtx(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(10, vector<ll>(10, 0));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j])%mod;
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}

map<ll, vector<vector<ll>>> m;

vector<vector<ll>> powMtx(vector<vector<ll>> a, ll k)
{
	if (m.count(k) != 0) return m[k];
	if (k == 1) return a;
	else if (k % 2 == 1) return m[k] = mulMtx(a, powMtx(a, k - 1));
	vector<vector<ll>> tmp = powMtx(a, k / 2);
	return m[k] = mulMtx(tmp, tmp);
}

void solve()
{
	matrix = vector<vector<ll>>(10, vector<ll>(10, 0));
	matrix[1][2] = matrix[1][3] = 1;
	matrix[2][1] = matrix[2][3] = matrix[2][4] = 1;
	matrix[3][1] = matrix[3][2] = matrix[3][4] = matrix[3][5] = 1;
	matrix[4][2] = matrix[4][3] = matrix[4][5] = matrix[4][6] = 1;
	matrix[5][3] = matrix[5][4] = matrix[5][6] = matrix[5][7] = 1;
	matrix[6][4] = matrix[6][5] = matrix[6][8] = 1;
	matrix[7][5] = matrix[7][8] = 1;
	matrix[8][6] = matrix[8][7] = 1;
	ll d; cin >> d;
	vector<vector<ll>> ans = powMtx(matrix, d);
	cout << ans[1][1] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


