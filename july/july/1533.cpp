
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<ll, ll>
#define pll pair<ll, ll>
// ll_MAX ll_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
ll n, s, e, t;
vector<vector<ll>> graph;
const ll mod = 1000003;

vector<vector<ll>> mulMatrix(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(n * 5 + 1, vector<ll>(n * 5 + 1,0));
	for (int i = 1; i <= 5 * n; i++)
	{
		for (int j = 1; j <= 5 * n; j++)
		{
			for (int k = 1; k <= 5 * n; k++)
			{
				ret[i][j] += (a[i][k] * b[k][j]) % mod;
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}
vector<vector<ll>> go(vector<vector<ll>> a, ll k)
{
	if (k == 1) return a;
	if (k % 2 == 1) return mulMatrix(go(a, k-1), a);
	vector<vector<ll>> tmp = go(a, k / 2);
	return mulMatrix(tmp, tmp);
}


void solve()
{
	cin >> n >> s >> e >> t;
	vector<vector<ll>> a(n+1, vector<ll>(n+1));
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			char c; cin >> c;
			a[i][j] = c - '0';
		}
	}
	
	graph = vector<vector<ll>>(5 * n + 1, vector<ll>(5 * n + 1,0));
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			if (a[i][j] == 0 || a[i][j]>5) continue;
			ll u = i * 5 - 4;
			ll v = (j * 5 - 4) + a[i][j] - 1;
			graph[u][v] = 1;
		}
	}
	for (ll i = 1; i <= 5*n; i+=5)
	{
		for (ll j = i; j < i + 4; j++)
		{
			 graph[j + 1][j] = 1;
		}
	}
	
	vector<vector<ll>> ans = go(graph, t);

	
	cout << ans[s * 5 - 4][e * 5 - 4] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


