
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
int dp[100001];
int fail[10001];
bool can_use[501][100001];
int len[10001];
string S, P;
int n, s;

int go(int idx)
{
	if (idx == s) return 0;
	int& ret = dp[idx];
	if (ret != -1) return ret;
	ret = go(idx + 1);
	for (int i = 0; i < n; i++)
	{
		if (can_use[i][idx]) ret = max(ret, len[i] + go(idx + len[i]));
	}
	return ret;
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	
	cin >> S >> n;
	s = S.size();
	for (int k = 0; k < n; k++)
	{
		cin >> P;
		memset(fail, 0, sizeof(fail));
		int p = P.size();
		len[k] = p;

		for (int i = 1, j = 0; i < p; i++)
		{
			while (j > 0 && P[i] != P[j]) j = fail[j - 1];
			if (P[i] == P[j]) fail[j]++;
		}

		for (int i = 0, j = 0; i < s; i++)
		{
			while (j && S[i] != P[j]) j = fail[j - 1];
			if (S[i] == P[j])
			{
				if (j == p - 1)
				{
					can_use[k][i - j] = true; 
					j = fail[j];
				}
				else
				{
					j++;
				}
			}
		}
	}
	cout << go(0) << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


