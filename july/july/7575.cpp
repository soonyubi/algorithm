
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
vector<int> p[101];
vector<vector<int>> virus;
vector<int> getFail(vector<int> p)
{
	int m = (int)p.size();
	vector<int> fail(m, 0);
	for (int i = 1, j = 0; i < m; i++)
	{
		while (j && p[i] != p[j]) j = fail[j - 1];
		if (p[i] == p[j]) fail[j] = ++j;
	}
	return fail;
}

bool kmp(vector<int> s, vector<int> p)
{
	int n = (int)s.size(), m = (int)p.size();
	auto fail = getFail(p);

	for (int i = 0, j = 0; i < n; i++)
	{
		while (j && s[i] != p[j]) j = fail[j - 1];
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
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int mi; cin >> mi;
		for (int j = 0; j < mi; j++)
		{
			int x; cin >> x;
			p[i].push_back(x);
		}
	}

	// p[0][0]~p[0][k-1] .... p[0][mi-k]~p[0][mi-1] ¸¦ »Ì¾Æ¼­ [1,n) ¿¡ kmp
	
	for (int idx = 0; idx <= p[0].size() - k; idx++)
	{
		vector<int> tmp;
		for (int i = idx; i < idx + k; i++)
		{
			tmp.push_back(p[0][i]);
		}
		virus.push_back(tmp);
	}
	vector<bool> chk(n, false);
	for (auto v : virus)
	{
		
		for (int i = 1; i < n; i++)
		{
			if (kmp(p[i], v))
			{
				//cout << i << " : ";
				
				chk[i] = true;
			}
			
		}
	}
	for (auto v : virus)
	{
		reverse(v.begin(), v.end());
		for (int i = 1; i < n; i++)
		{
			if (kmp(p[i], v))
			{
				//cout << i << " : ";

				chk[i] = true;
			}

		}
	}
	for (int i = 1; i < n; i++)
	{
		if (!chk[i])
		{
			
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


