
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
ll ans[10];

void calc(ll n, ll k)
{
	while (n > 0)
	{
		ans[n % 10] += k;
		n /= 10;
	}
}
void solve()
{
	ll end; cin >> end;
	ll start = 1;
	ll k = 1;

	while (start <= end)
	{
		while (start % 10 != 0 && start <= end)
		{
			calc(start, k);
			start++;
		}
		if (start > end) break;
		while (end % 10 != 9 && start <= end)
		{
			calc(end, k);
			end--;
		}
		ll cnt = (end / 10 - start / 10 + 1);
		for (int i = 0; i < 10; i++)
		{
			ans[i] += cnt*k;
		}
		end /= 10;
		start /= 10;
		k *= 10ll; 
	}
	for (int i = 0; i < 10; i++)
	{ 
		cout << ans[i] << " ";
	}cout << "\n";

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


