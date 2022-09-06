
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
	if (k == 0)
	{
		for (int i = 0; i < n/2; i++)
		{
			cout << i << " " << n - i - 1 << "\n";
		}
	}
	else if (k == n - 1)
	{
		if (n == 4)
		{
			cout << "-1\n";
			return;
		}
		
		cout << n - 1 << " " << n - 2 << "\n"; // n-2
		cout << n - 3 << " " << 1 << "\n"; //1 
		cout << 0 << " " << 2 << "\n";
		for (int i = 3; i < n / 2; i++)
		{
			cout << i << " " << (i ^ (n - 1)) << "\n";
		}
		

	}
	else
	{
		int k_ = k ^ (n - 1);
		cout << k << " " << n - 1 << "\n";
		cout << k_ << " " << 0 << "\n";
		vector<bool> visited(n, false);
		visited[k] = visited[k_] = visited[n - 1] = visited[0] = true;
		for (int i = 0; i < n; i++)
		{
			if (visited[i]) continue;
			cout << i << " " << (i ^ (n - 1)) << "\n";
			visited[i] = visited[i ^ (n - 1)] = true;
		}
	}
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


