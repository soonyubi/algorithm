
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

vector<int> solution(int n, vector<int> info) {
	vector<int> answer;
	return answer;
}

vector<int> info;

void solve()
{
	int n; cin >> n;
	info.resize(11);
	for (int& x : info) cin >> x;

	int mx = -1; vector<int> ans(11, 0);
	for (int i = 0; i < (1<<11); i++)
	{
		vector<int> temp(11, 0);
		int cnt = 0;
		for (int j = 0; j < 11; j++)
		{
			if (i & (1 << j))
			{
				temp[j] = info[j] + 1;
				cnt += temp[j];
			}
		}
		if (cnt > n) continue;
		if (cnt < n) temp[10] += (n-cnt);
		int score = 0;
		for (int j = 0; j < 11; j++)
		{
			if (temp[j] > info[j]) score += (10 - j);
			else if (temp[j] < info[j]) score -= (10 - j);
		}
		if (score < 0) continue;
		if (mx < score)
		{
			ans = temp;
			mx = score;
			continue;
		}
		if (mx == score)
		{
			for (int j = 10; j >= 0; j--)
			{
				if (temp[j] > ans[j])
				{
					ans = temp;
					break;
				}
				else if (ans[j] > temp[j]) break;
			}
		}
	}
	if(mx==0
	if (mx == -1)
	{
		cout <<"-1";
	}
	else
	{
		cout << mx << "\n";
		for (auto u : ans) cout << u << " "; cout << "\n";
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


