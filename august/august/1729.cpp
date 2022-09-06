
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


void go(int cur,vector<vector<int>> board)
{
	vector<vector<int>> temp(6,vector<int>(6));
	int temp_sum = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			temp[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
	{

	}
	
}
void solve()
{
	vector<vector<int>> board(6, vector<int>(6));
	int sum = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> board[i][j];
			sum += board[i][j];
		}
	}
	go(sum, board);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


