
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
ll n, k;
const ll mod = 1e9 + 7;
vector<vector<ll>> mulMtx(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(k + 1, vector<ll>(k + 1, 0));
	for (int i = 0; i < k + 1; i++)
	{
		for (int j = 0; j < k + 1; j++)
		{
			for (int l = 0; l < k + 1; l++)
			{
				ret[i][j] = (ret[i][j] + a[i][l] * b[l][j]) % mod;
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}
vector<vector<ll>> powMtx(vector<vector<ll>> a, ll t)
{
	if (t == 1) return a;
	else if (t % 2 == 1) return mulMtx(a, powMtx(a, t - 1));
	vector<vector<ll>> temp = powMtx(a, t / 2);
	return mulMtx(temp, temp);
}

void solve()
{
	 cin >> k >> n;
	 if (n == 1)
	 {
		 cout << "1\n";
		 return;
	 }
	vector<vector<ll>> matrix(k + 2, vector<ll>(k + 2, 0));
	for (int i = 0; i < k + 2; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			matrix[i][j] = 1;
		}
	}
	vector<vector<ll>> ans = powMtx(matrix, n - 1);
	vector<ll> a(k + 2, 1);
	a[0] = n;
	ll sum = 0;
	for (int i = 0; i < k + 1; i++)
	{
		sum = (sum + ans[k][i] * a[i]) % mod;
	}
	sum %= mod;
	cout << sum << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


