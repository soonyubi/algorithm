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

int dp[111111];
int fail[111111];
bitset<111111> can[505];
vector<string> P;
string S;
int N;


void KMP()
{
	for (int k = 1; k <= N; k++)
	{
		memset(fail, 0, sizeof(fail));

		int m = (int)P[k].size(), j = 0;
		for (int i = 1; i < m; i++)
		{
			while (j && P[k][i] != P[k][j]) j = fail[j - 1];
			if (P[k][i] == P[k][j]) fail[i] = ++j;
		}
		
		int n = (int)S.size(); j = 0;
		for (int i = 0; i < n; i++)
		{
			while (j && S[i] != P[k][j]) j = fail[j - 1];
			if (S[i] == P[k][j])
			{
				if (j == m - 1)
				{
					can[k][i - m + 1] = true;
					j = fail[j];
				}
				else
				{
					j++;
				}
			}
		}
	}
}

int go(int idx)
{
	if (idx >= S.size()) return 0;
	int& ret = dp[idx];
	if (ret != -1) return ret;
	ret = go(idx + 1);
	for (int i = 1; i <= N; i++)
	{
		if (can[i][idx])
		{
			ret = max(ret, go(idx + (int)P[i].size()) + (int)P[i].size());
		}
	}
	return ret;
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	P.push_back("");
	cin >> S; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string temp; cin >> temp;
		P.push_back(temp);
	}

	KMP();

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


