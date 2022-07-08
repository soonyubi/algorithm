
/*
*   Time :
*   Subject : union find + sort 
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
bool num[4000001];
int par[4000001];
int p[4000001];

int getPar(int x)
{
	if (par[x] == -1) return x;
	return par[x] = getPar(par[x]);
}

void merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);
	if (a == b) return;
	par[a] = b;
}
void solve()
{
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		num[x] = true;
	}
	vector<int> v;
	for (int i = 1; i <= 4000000; i++)
	{
		if (num[i]) {
			v.push_back(i);
			p[i] = v.size() - 1;
		}
	}
	
	memset(par, -1, sizeof(par));

	for (int i = 0; i < k; i++)
	{
		int x; cin >> x;
		int x_ = v[upper_bound(v.begin(), v.end(), x) - v.begin()];
		if (par[x_] == -1)
		{
			cout << x_ << "\n";
			if(p[x_]+1 < v.size()) merge(v[p[x_]], v[p[x_] + 1]);
		}
		else
		{
			int a = getPar(x_);
			cout << a << "\n";
			if(p[a]+1 < v.size()) merge(v[p[a]], v[p[a] + 1]);
		}
		
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


