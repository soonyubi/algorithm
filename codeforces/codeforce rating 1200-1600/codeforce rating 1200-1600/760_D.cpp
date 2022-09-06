
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
	int n, k; cin >> n >> k;
	vector<int> v(n); 
	for (int& x : v) cin >> x;
	vector<int> to_erase;
	sort(v.begin(), v.end());
	for (int i = 0; i < 2 * k; i++)
	{
		int t = v.back(); v.pop_back();
		to_erase.push_back(t);
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) ans += v[i];

	for (int i = 0; i < k; i++)
	{
		ans +=  to_erase[i+k] / to_erase[i];
	}

	cout << ans << "\n";

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


