
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
int par[100001];
int getPar(int x)
{
	if (par[x] == x) return x;
	else return par[x] = getPar(par[x]);
}

void merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);
	//if (a == b) return;
	if (a < b) par[b] = a;
	else par[a] = b;
}
void solve()
{
	
	int g, n; cin >> g >> n;
	vector<int> v(n + 1);
	//for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= g; i++) par[i] = i;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		int x = getPar(v[i]);
		if (x == 0)
		{
			cout << i - 1 << "\n";
			return;
		}
		merge(x, x - 1);
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


