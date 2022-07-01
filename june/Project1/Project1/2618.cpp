
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
int dp[1001][1001]; // dp[i][j] : 1번이 i사건 2번이 j사건을 처리했을 때 남아있는 최소 이동거리
int n, m; 
pii car1[1001], car2[1001];

int go(int c1, int c2)
{
	if (c1 == m || c2 == m) return 0;
	int& ret = dp[c1][c2];
	if (ret != -1) return ret;

	int next = max(c1, c2) + 1;
	int dist1 = abs(car1[c1].first - car1[next].first) + abs(car1[c1].second - car1[next].second);
	int n1 = go(next, c2) + dist1;

	int dist2 = abs(car2[c2].first - car2[next].first) + abs(car2[c2].second - car2[next].second);
	int n2 = go(c1, next) + dist2;

	return ret = min(n1, n2);
}
vector<int> track;
void tracking(int c1, int c2)
{
	if (c1 == m || c2 == m) return;
	int next = max(c1, c2) + 1;
	int dist1 = abs(car1[c1].first - car1[next].first) + abs(car1[c1].second - car1[next].second);
	int n1 = dp[next][c2] + dist1;

	int dist2 = abs(car2[c2].first - car2[next].first) + abs(car2[c2].second - car2[next].second);
	int n2 = dp[c1][next] + dist2;

	if (n1 > n2)
	{
		track.push_back(2);
		tracking(c1, next);
	}
	else
	{
		track.push_back(1);
		tracking(next, c2);
	}
}
void solve()
{
	cin >> n >> m;
	car1[0] = { 1,1 };
	car2[0] = { n,n };

	for (int i = 1; i <= m; i++)
	{
		int x, y; cin >> x >> y;
		car1[i] = car2[i] = { x,y };
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << "\n";
	tracking(0, 0);
	for (auto u : track) cout << u << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


