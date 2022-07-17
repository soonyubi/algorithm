
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
	int n; cin >> n;
	string s, t; cin >> s >> t;
	if (s == t)
	{
		cout << "YES\n";
		return;
	}
	vector<int> cnt1(3, 0);
	vector<int> cnt2(3, 0);
	for (int i = 0; i < s.size(); i++)
	{
		cnt1[s[i] - 'a']++;
		cnt2[t[i] - 'a']++;
	}
	for (int i = 0; i < 3; i++)
	{
		if (cnt1[i] != cnt2[i])
		{
			cout << "NO\n";
			return;
		}
	}

	vector<pair<char, int>> pos1;
	vector<pair<char, int>> pos2;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'c') pos1.push_back({ s[i],i });
		if (t[i] == 'a' || t[i] == 'c') pos2.push_back({ t[i],i });
	}

	for (int i = 0; i < pos1.size(); i++)
	{
		if (pos1[i].first == pos2[i].first)
		{
			if (pos1[i].first == 'a')
			{
				// a일 경우 t에서의 위치가 크거나 같아야됌
				if (pos1[i].second > pos2[i].second)
				{
					cout << "NO\n";
					return;
				}
			}
			else
			{
				// c 일경우 t에서의 위치가 작거나 같아야됌
				if (pos1[i].second < pos2[i].second)
				{
					cout << "NO\n";
					return;
				}
			}
		}
		else
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
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


