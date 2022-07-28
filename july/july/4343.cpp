
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii  pair<int, int>
#define pll pair<ll, ll>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int par[501];
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
	if (a < b)
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
	}
}
ld getDist(pair<ld, ld> a, pair<ld, ld> b)
{
	ld dx = b.first - a.first;
	ld dy = b.second - a.second;
	return sqrt(dx * dx + dy * dy);
}
void solve()
{
	int s,n; cin >> s >> n;
	vector<pair<ld,ld>> v(n);
	for (auto& x : v)  cin >> x.first >> x.second;
	vector<pair<ld, pair<ld,ld>>> conn;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			ld dist = getDist(v[i], v[j]);
			conn.push_back({ dist,{i,j} });
		}
	}
	memset(par, -1, sizeof(par));
	sort(conn.begin(), conn.end());
	int T = n - s;
	for (int i = 0; i < conn.size(); i++)
	{
		int u = conn[i].second.first;
		int v = conn[i].second.second;
		ld d = conn[i].first;
		if (getPar(u) == getPar(v)) continue;
		merge(u, v);
		T--;
		if (T == 0)
		{
			cout << fixed;
			cout.precision(2);
			cout << d << "\n";
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


