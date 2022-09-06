
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

int n;
bool visited[1 << 20];
int mx = 0;
vector<int> ans;
vector<int> cur;

void go(int idx,int participate)
{
	
	if (participate == 0 && idx != 0)
	{
		if (mx < idx)
		{
			mx = idx;
			ans = cur;
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if ((1 << i) & participate)
		{
			int temp = participate & (~(1 << i));
			if (!visited[temp]|| (idx!=0&&temp==0))
			{
				visited[temp] = true;
				cur.push_back(i+1);
				go(idx + 1, temp);
				cur.pop_back();
			}
		}
		else
		{
			int temp = participate | (1 << i);
			if (!visited[temp])
			{
				visited[temp] = true;
				cur.push_back(i+1);
				go(idx + 1, temp);
				cur.pop_back();
			}
		}
	}
}
void solve()
{
	cin >> n;
	
	go(0, 0);
	cout << mx-1 << "\n";
	for (auto u : ans) cout << u << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


