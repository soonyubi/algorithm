
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

const int MAXN = 1'000'001;
vector<ll> segTree(MAXN*4);

//segTree[ptr] = ptr에 해당하는 범위의 순위가 가지고 있는 사탕의 갯수

void update(int ptr, int s, int e, int i, ll value)
{
	if (s > i || e < i) return;
	segTree[ptr] += value;
	if (s == e) return;

	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, value);
	update(ptr * 2 + 1, mid + 1, e, i, value);

}

int getRank(int ptr, int s, int e, ll value)
{
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (segTree[ptr * 2] >= value)
	{
		return getRank(ptr * 2, s, mid, value);
	}
	else
	{
		return getRank(ptr * 2 + 1, mid + 1, e, value - segTree[ptr * 2]);
	}
}
void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c; cin >> a;
		if (a == 1)
		{
			cin >> b;
			int r = getRank(1, 1, MAXN, b);
			cout << r << "\n";
			update(1, 1, MAXN, r, -1);
		}
		else
		{
			cin >> b >> c;
			update(1, 1, MAXN, b, c);
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


