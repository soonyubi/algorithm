
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

int n, k, m;
vector<vector<bool>> init_path;

vector<vector<bool>> mulMtx(vector<vector<bool>> a, vector<vector<bool>> b)
{
	vector<vector<bool>> ret(n + 1, vector<bool>(n + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (a[i][k] & b[k][j]) ret[i][j] = true;
			}
		}
	}
	return ret;
}
vector<vector<bool>> powMtx(vector<vector<bool>> a, int k)
{
	if (k == 1) return a;
	else if (k % 2 == 1) return mulMtx(a, powMtx(a, k - 1));
	vector<vector<bool>> tmp = powMtx(a, k / 2);
	return mulMtx(tmp, tmp);
}

void solve()
{
	cin >> n >> k >> m;
	init_path = vector<vector<bool>>(n + 1, vector<bool>(n + 1,0));
	for (int i = 1; i <= n; i++)
	{
		int a, b; cin >> a >> b;
		init_path[i][a] = 1;
		init_path[i][b] = 1;
	}
	vector<vector<bool>> ans = powMtx(init_path, k);
	
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		if (ans[a][b]) cout << "death\n";
		else cout << "life\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


