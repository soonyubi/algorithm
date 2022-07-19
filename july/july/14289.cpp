
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
ll n, m; 
vector<vector<ll>> matrix;
const ll mod = 1e9 + 7;
vector<vector<ll>> mulMtx(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}
map<ll, vector<vector<ll>>> mp;

vector<vector<ll>> powMtx(vector<vector<ll>> a, ll k)
{
	if (mp.count(k)) return mp[k];
	if (k == 1) return a;
	else if (k % 2 == 1)return  mp[k] = mulMtx(a, powMtx(a, k - 1));
	mp[k / 2] = powMtx(a, k / 2);
	return mp[k] = mulMtx(mp[k / 2], mp[k / 2]);
}
void solve()
{
	cin >> n >> m;
	matrix = vector<vector<ll>>(n + 1, vector<ll>(n + 1));
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		matrix[a][b] = matrix[b][a] = 1;
	}
	ll d; cin >> d;
	vector<vector<ll>> ans = powMtx(matrix, d);
	cout << ans[1][1] % mod << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


