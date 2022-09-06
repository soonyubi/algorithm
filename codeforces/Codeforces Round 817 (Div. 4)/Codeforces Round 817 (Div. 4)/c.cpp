
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
map<string, int> mp;
void solve()
{
	mp.clear();
	int n; cin >> n;
	vector<string> v[3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			string s; cin >> s;
			v[i].push_back(s);
			mp[s]++;
		}
	}
	int score[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mp[v[i][j]] == 1) score[i] += 3;
			else if (mp[v[i][j]] == 2) score[i] += 1;
		}
	}
	for (int i = 0; i < 3; i++) cout << score[i] << " "; cout << "\n";
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


