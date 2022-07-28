
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

vector<int> adj1[10];
vector<int> adj2[10];
int inDegree1[10];
int inDegree2[10];

void solve()
{
	int n; cin >> n;
	int k1 = 0, k2 = 9;
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		if (c == '<')
		{
			adj1[k1].push_back(k1 + 1);
			inDegree1[k1 + 1]++;
			adj2[k2 - 1].push_back(k2);
			inDegree2[k2]++;
			k1++, k2--;
		}
		else
		{
			adj1[k1 + 1].push_back(k1);
			inDegree1[k1]++;
			adj2[k2].push_back(k2 - 1);
			inDegree2[k2 - 1]++;
			k1++, k2--;
		}
	}

	vector<int> topology1, topology2;

	priority_queue<int, vector<int>, greater<int>> pq1;
	priority_queue<int> pq2;

	for (int i = 0; i <= n; i++)
	{
		if (inDegree1[i] == 0) pq1.push(i);
		if (inDegree2[9 - i] == 0) pq2.push(9 - i);
	}

	for (int i = 0; i <= n; i++)
	{
		if (pq1.empty())
		{
			cout << "-1\n";
			break;
		}

		int v = pq1.top();
		pq1.pop();
		topology1.push_back(v);
		for (auto nv : adj1[v])
		{
			if (--inDegree1[nv] == 0)
			{
				pq1.push(nv);
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		if (pq2.empty())
		{
			cout << "-1\n";
			break;
		}

		int v = pq2.top();
		pq2.pop();
		topology2.push_back(v);
		for (auto nv : adj2[v])
		{
			if (--inDegree2[nv] == 0)
			{
				pq2.push(nv);
			}
		}
	}
	for (auto u : topology2) cout << u; cout << "\n";
	for (auto u : topology1) cout << u; cout << "\n";
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


