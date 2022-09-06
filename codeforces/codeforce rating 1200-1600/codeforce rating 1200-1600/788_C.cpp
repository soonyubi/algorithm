
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

const int maxn = 1e5 + 1;
int a[maxn];
int pa[maxn];
int b[maxn];
int pb[maxn];
int c[maxn];
vector<bool> visited;
vector<bool> visited_b;
const int mod = 1e9 + 7;
int dfs(int x, int first, bool odd,int cnt,bool flag)
{
	visited[x] = true;
	
	if (x == first)
	{
		if (flag) return 2;
		else return cnt;
	}
	if (c[x] != 0) flag = true;
	if (odd)
	{
		
		return dfs(x, first, false, cnt + 1, flag);
	}
	else
	{
		return dfs(pb[x], first, true, cnt + 1, flag);
	}
}

void solve()
{
	int n; cin >> n;
	visited = vector<bool>(n + 1, false);

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pa[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		pb[i] = pa[b[i]];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	// 해당 사이클에 포함된 값중 c에 값이 있는 경우 해당 값은 1로 처리
	ll ans = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			
			ll temp = dfs(pb[i], i, true, 2, false);
			if (c[i] != 0) temp = 2;
			if (temp > 2) ans = (ans*2)%mod;
		}
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i++)
	{
		pa[i] = pb[i] = a[i] = b[i] = c[i] = 0;
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


