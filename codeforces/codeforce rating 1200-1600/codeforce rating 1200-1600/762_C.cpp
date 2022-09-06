
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
	string a, s; cin >> a >> s;
	int sz = max(a.size(), s.size());
	vector<int> A(a.size());
	vector<int> S(s.size());
	vector<int> ans;
	for (int i = 0; i < a.size(); i++) A[i] = a[i] - '0';
	for (int i = 0; i < s.size(); i++) S[i] = s[i] - '0';
	
	while (true)
	{
		
		if ((!A.empty() && S.empty()))
		{
			cout << "-1\n";
			return;
		}
		if (A.empty() && !S.empty())
		{
			int t2 = S.back(); S.pop_back();
			ans.push_back(t2);
			continue;
		}
		if (A.empty() && S.empty())
		{
			break;
		}

		int t1 = A.back(); A.pop_back();
		int t2 = S.back(); S.pop_back();
		if (t1 <= t2)
		{
			ans.push_back(t2 - t1);
			
		}
		else
		{
			int t3 = S.back(); S.pop_back();
			if (t3 != 1)
			{
				cout << "-1\n";
				return;
			}
			ans.push_back(t3 * 10 + t2 - t1);
		}
		
	}
	
	while (!ans.empty() && ans.back() == 0) ans.pop_back();
	reverse(ans.begin(), ans.end());
	for (auto u : ans)
	{
		cout << u;
	}cout << "\n";

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


