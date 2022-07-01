
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
int par[100001];
int height[100001];

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
struct compare
{
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
	{
		return a.first > b.first;
	}
};
void solve()
{
	memset(par, -1, sizeof(par));
	int n; cin >> n;
	vector<pair<int,int>> xx;
	vector<pair<int, int>> yy;
	vector<pair<int, int>> zz;
	for (int i = 0; i < n; i++)
	{
		int x, y, z; cin >> x >> y >> z;
		xx.push_back({ x,i });
		yy.push_back({ y,i });
		zz.push_back({ z,i });
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	sort(zz.begin(), zz.end());

	
	priority_queue<pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, compare> pq;
	for (int i = 0; i < n-1; i++)
	{
		pq.push({ xx[i + 1].first - xx[i].first,{xx[i + 1].second,xx[i].second} });
		pq.push({ yy[i + 1].first - yy[i].first,{yy[i + 1].second,yy[i].second} });
		pq.push({ zz[i + 1].first - zz[i].first,{zz[i + 1].second,zz[i].second} });
	}

	int cnt = 0;
	int ans = 0;
	while (!pq.empty())
	{
		if (cnt == n - 1) break;

		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int c = pq.top().first;
		pq.pop();

		if (getPar(u) == getPar(v)) continue;
		merge(u, v);
		ans += c;
	}
	cout << ans << "\n";
}
int main()
{
	solve();
	return 0;
}