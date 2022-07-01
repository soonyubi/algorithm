
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
int dp[1001][3]; int arr[1001][3];
const int inf = 1e9;
void solve()
{
	int n; cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	int ans = inf;

	for (int i = 0; i < 1001; i++) for (int j = 0; j < 3; j++) dp[i][j] = inf;
	dp[1][0] = arr[1][0];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i][2];
	}
	
	int temp_min = min(dp[n][1], dp[n][2]);
	ans = min(temp_min, ans);

	
	for (int i = 0; i < 1001; i++) for (int j = 0; j < 3; j++) dp[i][j] = inf;
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i][2];
	}
	temp_min = min(dp[n][0], dp[n][2]);
	ans = min(temp_min, ans);
	
	for (int i = 0; i < 1001; i++) for (int j = 0; j < 3; j++) dp[i][j] = inf;
	dp[1][2] = arr[1][2];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i][2];
	}
	temp_min = min(dp[n][1], dp[n][0]);
	ans = min(temp_min, ans);
	
	cout << ans << "\n";
}
int main()
{
	solve();
	return 0;
}


