
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
	assert(n != -1);
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r) / 2;
		cout << "?" << ' ' << l << " " << mid << endl;
		int x, cnt = 0;
		for (int i = 0; i < mid - l + 1; i++)
		{
			cin >> x;
			//assert(x != -1);
			if (l <= x && x <= mid) cnt++;
		}
		if (cnt % 2 == 0) l = mid + 1;
		else r = mid;
	}
	cout << "!" << ' ' << l << endl;
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


