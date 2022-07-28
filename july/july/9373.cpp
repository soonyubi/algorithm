
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<int, int>
#define ld long double
#define pll pair<ll, ll>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int par[1111];
int height[1111];
struct circle
{
	ld x, y, r;
};
struct EDGE
{
	ld d; 
	int u, v; 
};
ld dist(circle a, circle b)
{
	ld dx = a.x - b.x;
	ld dy = a.y - b.y;
	ld d = sqrt(dx * dx + dy * dy) - a.r - b.r;
	return max(d, (ld)0);
}
int getPar(int a)
{
	if (par[a] == -1) return a;
	return par[a] = getPar(par[a]);
}
bool merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);
	if (a == b) return false;
	if (height[a] < height[b])
	{
		par[a] = b;
	}
	else
	{
		par[b] = a;
		if (height[a] == height[b]) height[b]++;
	}
	return true;
}
bool cmp(EDGE a, EDGE b)
{
	return a.d < b.d;
}
void solve()
{
	ld w, n; cin >> w >> n;
	vector<circle> v(n);
	for (auto& u : v)
	{
		cin >> u.x >> u.y >> u.r;
	}

	if (n == 0)
	{
		cout << fixed;
		cout.precision(6);
		cout << w / 2.0 << "\n";
		return;
	}
	vector< EDGE> edge;

	for (int i = 0; i < n; i++)
	{
		ld l = max((ld)0, v[i].x - v[i].r);
		ld r = max((ld)0, w - (v[i].x + v[i].r));
		EDGE e1, e2; 
		e1.d = l, e1.u = i, e1.v = n;
		e2.d = r , e2.u = i, e2.v = n+1;
		edge.push_back(e1);
		edge.push_back(e2);
		for (int j = 0; j < i; j++)
		{
			EDGE e1;
			e1.u = i, e1.v = j, e1.d = dist(v[i], v[j]);
			edge.push_back(e1);
		}
	}

	memset(par, -1, sizeof(par));
	memset(height, 0, sizeof(height));
	sort(edge.begin(), edge.end(), cmp);

	for (int i = 0; i < edge.size(); i++)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		ld d = edge[i].d;

		if (merge(u, v))
		{
			if (getPar(n) == getPar(n + 1))
			{
				if (d == 0) cout << "0\n";
				else
				{
					cout << fixed;
					cout.precision(6);
					cout << d / 2.0 << "\n";
					break;
				}
			}
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


