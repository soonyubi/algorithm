
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
const int maxn = 360000;

vector<int> getFail(string p)
{
	int m = (int)p.size(), j = 0;
	vector<int> fail(m, 0);
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j]) j = fail[j - 1];
		if (p[i] == p[j]) fail[j] = ++j;
	}

	return fail;
}
bool kmp(string s, string p)
{
	auto fail = getFail(p);
	int n = (int)s.size(), m = (int)p.size(), j=0;

	for (int i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j]) j = fail[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				return true;
			}
			else
			{
				j++;
			}
		}
	}
	return false;
}
void solve()
{
	int n; cin >> n;
	
	string S(maxn * 2, '0');
	string T(maxn, '0');
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		S[x] = S[maxn + x] = '1';
	}
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		T[x] = '1';
	}
	if (kmp(S, T)) cout << "possible\n";
	else cout << "impossible\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


