
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
const ll mod = 1e9 + 9;
ll a1, a2, n, m;
vector<vector<ll>> mulMtx(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(n + 2, vector<ll>(n + 2, 0));
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= n+1; j++)
		{
			for (int k = 0; k <= n+1; k++)
			{
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}
map<ll, vector<vector<ll>> > mp;

vector<vector<ll>> powMtx(vector<vector<ll>> a, ll k)
{
	if (mp.count(k)) return mp[k];
	if (k == 1) return a;
	else if (k % 2 == 1) return mp[k] = mulMtx(a, powMtx(a, k - 1));
	if (mp.count(k / 2)) return mp[k / 2];
	mp[k/2] =  powMtx(a,k/2);
	return mulMtx(mp[k / 2], mp[k / 2]);
}

void solve()
{
	mp.clear();
	cin >> a1 >> a2 >> n >> m;
	if (m == 1)
	{
		cout << a1 << "\n";
		return;
	}
	vector<vector<ll>> matrix(n + 2, vector<ll>(n+2,0));
	
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			matrix[i][j] = 1;
		}
	}
	matrix[0][0] = 0;
	matrix[0][1] = 1;

	vector<vector<ll>> A = powMtx(matrix, m-1); // (n+2) by (n+2)
	
	vector<ll> B(n + 2, a1); 
	ll tmp = a2 - a1;
	while (tmp < 0)
	{
		tmp += mod;
	}
	tmp %= mod; B[0] = tmp;

	vector<ll> ans(n + 2, 0);
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= n+1; j++)
		{
			ans[i] = (ans[i] + A[i][j] * B[j]) % mod;
		}
		ans[i] %= mod;
	}

	cout << ans[n+1] << "\n";

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}


