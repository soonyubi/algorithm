
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int par[500001];
int height[500001];

int getPar(int a)
{
	if (par[a] == -1) return a;
	else return par[a] = getPar(par[a]);
}

void merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);

	if (a == b) return;

	if (height[a] < height[b])
	{
		par[a] = b;
	}
	else
	{
		par[b] = a;
		if (height[a] == height[b]) height[b]++;
	}
}
void solve()
{
	memset(par, -1, sizeof(par));
	int n, m; cin >> n >> m;
	vector<pair<int, int>> vv(m);
	for (auto& x : vv)
	{
		cin >> x.first >> x.second;
	}
	for (int i = 0; i < m; i++)
	{
		int u = vv[i].first;
		int v = vv[i].second;
		if (getPar(u) == getPar(v))
		{
			cout << i+1 << "\n";
			return;
		}
		merge(u, v);
	}
	cout << "0\n";
}
int main()
{
	solve();
	return 0;
}


