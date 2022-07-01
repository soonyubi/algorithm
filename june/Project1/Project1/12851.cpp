
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

bool visited[100001];
int dist[100001];
const int inf = 1e9;
int ans,cnt;
bool isRange(int x)
{
	if (x >= 0 && x <= 100000) return true;
	return false;
}
void bfs(int x,int k)
{
	
	for (int i = 0; i < 100001; i++) dist[i] = inf;
	queue<pair<int, int>> q;
	q.push({ x,0 });
	visited[x] = true;
	dist[0] = 0;
	while (!q.empty())
	{
		int v = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if (ans != 0 && ans < time) return;
		if (ans == time && v == k) cnt++;
		if (ans == 0 && v == k)
		{
			ans = time;
			cnt++;
		}
		int nv = v + 1;
		if(isRange(nv)&&!visited[nv]) 
		{
			visited[nv] = true;
			q.push({ nv,time + 1 });
		}
		nv = v - 1;
		if (isRange(nv) && !visited[nv])
		{
			visited[nv] = true;
			q.push({ nv,time + 1 });
		}
		nv = v * 2;
		if (isRange(nv) && !visited[nv])
		{
			visited[nv] = true;
			q.push({ nv,time + 1 });
		}
	}
}
void solve()
{
	int n, k; cin >> n >> k;
	if (n == k)
	{
		cout << "0\n1\n";
		return;
	}
	bfs(n, k);

	cout << ans << "\n" << cnt << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


