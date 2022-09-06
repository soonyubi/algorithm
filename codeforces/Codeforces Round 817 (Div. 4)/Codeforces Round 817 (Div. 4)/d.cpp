
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
	string s; cin >> s;
	string ans;
	for (int i = 0; i < (n + 1) / 2; i++) ans.push_back('R');
	for (int i = 0; i < n / 2; i++) ans.push_back('L');
	
	ll cnt = 0;
	for (ll i = 0; i < n; i++)
	{
		if (s[i] == 'R')
		{
			cnt += (n - 1 - i);
		}
		else
		{
			cnt += i;
		}
	}
	
	vector<ll> a;
	for (ll i = 0; i < n; i++)
	{
		
		ll diff = 0;
		if (s[i] == 'R')
		{
			diff = i - (n - 1 - i);
			
		}
		else
		{
			diff = (n - 1 - i) - i;
		}
		a.push_back(max(diff,0ll));
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		cnt += a[i];
		cout << cnt << " ";
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


