
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
	int n, m; cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(m));
	for (int i = 0;i<n; i++)
	{
		for (int j = 0;j<m; j++)
		{
			cin >> arr[i][j];
		}
	}
	vector<ll> brr = arr[0];
	sort(brr.begin(), brr.end());
	vector<int> bad;
	for (int i = 0; i < m; i++)
	{
		if (arr[0][i] != brr[i]) bad.push_back(i);
	}
	if (bad.size() == 0)
	{
		cout << "1 1\n";
		return;
	}
	if (bad.size() > 2)
	{
		cout << "-1\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		swap(arr[i][bad[0]], arr[i][bad[1]]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			if (arr[i][j] > arr[i][j + 1])
			{
				cout << "-1\n";
				return;
			}
		}
	}
	cout << bad[0] + 1 << " " << bad[1] + 1 << "\n";
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


