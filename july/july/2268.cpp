
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

int n, m;
vector<ll> arr;
vector<ll> segTree;

void update(int i, int x)
{
	while (i <= n)
	{
		segTree[i] += x;
		i += i & -i;
	}
}
ll getVal(int i)
{
	ll res = 0;
	while (i)
	{
		res += segTree[i];
		i -= i & -i;
	}
	return res;
}
void solve()
{
	cin >> n >> m;
	segTree = vector<ll>(4 * (n + 10));
	arr = vector<ll>(n + 10);

	for (int i = 0; i < m; i++)
	{
		ll op, a, b; cin >> op >> a >> b;
		if (op == 1)
		{
			update(a, b-arr[a]);
			arr[a] = b;
		}
		else
		{
			if (b < a) swap(a, b);
			cout << getVal(b) - getVal(a - 1) << "\n";
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


