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
string answer[15];
int score[15];
map<vector<int>, int > cnt;
vector<int> tmp, as;

void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> answer[i] >> score[i];
	}
	int m1 = m / 2;
	int m2 = m - m / 2;
	int ans = 0, mi;

	tmp.resize(n);
	as.resize(n);
	cnt.clear();

	for (int i = 0; i < (1 << m2); i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int k = 0; k < m2; k++)
			{
				if (((i >> k) & 1) == answer[j][k + m1] - '0') sum++;
			}
			tmp[j] = sum;
		}
		++cnt[tmp];
	}

	for (int i = 0; i < (1 << m1); i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum = 0;
			for (int k = 0; k < m1; k++)
			{
				if (((i >> k) & 1) == answer[j][k] - '0') sum++;
			}
			tmp[j] = sum;
		}
		for (int j = 0; j < n; j++)
		{
			tmp[j] = score[j] - tmp[j];
		}
		if (cnt[tmp])
		{
			ans += cnt[tmp];
			if (ans == 1)
			{
				mi = i;
				as = tmp;
			}
		}
	}

	if (ans != 1) cout << ans << " solutions\n";
	else
	{
		for (int k = 0; k < m1; k++)
		{
			cout << ((mi >> k) & 1);
		}
		for (int i = 0; i < (1 << m2); i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum = 0;
				for (int k = 0; k < m2; k++)
				{
					if (((i >> k) & 1) == answer[j][k + m1] - '0') sum++;
				}
				tmp[j] = sum;
			}
			if (tmp == as)
			{
				for (int k = 0; k < m2; k++)
				{
					cout << ((i >> k) & 1);
				}cout << "\n";
				break;
			}
		}

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


