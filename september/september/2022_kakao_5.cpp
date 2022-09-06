
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

int solution(vector<int> info, vector<vector<int>> edges) {
	int answer = 0;
	return answer;
}

vector<int> info;
vector<vector<int>> edges;
int par[22];

void solve()
{
	int n; cin >> n;
	info = vector<int>(n);
	edges = vector<vector<int>>(n - 1, vector<int>(2));
	for (int i = 0; i < n; i++) cin >> info[i];
	for (int i = 0; i < n - 1; i++)
	{
		cin >> edges[i][0] >> edges[i][1];
	}

	int answer = 0;
	for (int i = 0; i < n-1; i++)
	{
		par[edges[i][1]] = edges[i][0];
	}
	
	for (int i = 0; i < (1 << (n - 1)); i++)
	{
		set<int> st; st.insert(0);
		for (int j = 0; j < (n - 1); j++)
		{
			if (i & (1 << j)) st.insert(j + 1);
		}
		int a = 0, b = 0; bool flag = true;
		for (auto u : st)
		{
			if (info[u] == 0) a++;
			else b++;

			if (u != 0)
			{
				if (st.count(par[u]) == 0) flag = false;
			}
		}
		if (a+b <= 0) continue;
		if (!flag) continue;
		answer = max(answer, a);
		cout << a << "\n";
		for (auto u : st) cout << u << " "; cout << "\n";
		cout << "--------------------------------\n";
	}
	cout << answer << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


