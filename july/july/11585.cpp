
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
void solve()
{
	int N; cin >> N;
	string S, P;
	for (int i = 0; i < N; i++)
	{
		char c; cin >> c;
		S.push_back(c);
	}
	for (int i = 0; i < N; i++)
	{
		char c; cin >> c;
		P.push_back(c);
	}
	S = S + S;
	S.pop_back();
	int n = S.size(); int m = P.size();
	vector<int> fail(m, 0);
	for (int i = 1, j = 0; i < m; i++)
	{
		while (j > 0 && P[i] != P[j]) j = fail[j - 1];
		if (P[i] == P[j]) fail[i] = ++j;
	}
	int cnt = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && S[i] != P[j]) j = fail[j - 1];
		if (S[i] == P[j])
		{
			if (j == m - 1)
			{
				cnt++;
				j = fail[j];
			}
			else
			{
				j++;
			}
		}
	}
	ll g = gcd(N, cnt);
	cout << cnt / g << "/" << N / g << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


