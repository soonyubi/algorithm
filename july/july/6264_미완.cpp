
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
map<string, int> mp;
string str[101];
vector<string> dict[101];
set<int> adj[101];
vector<string> name;

int cnt;
int dfs_num[101];
int scc_num[101];
bool finished[101];
vector<vector<int>> SCC;
vector<int> stk;
int in[101];
int dfs(int v)
{
	dfs_num[v] = ++cnt;
	stk.push_back(v);

	int result = dfs_num[v];
	for (auto nv : adj[v])
	{
		if (!dfs_num[nv]) result = min(dfs(nv), result);
		else if (!finished[nv]) result = min(dfs_num[nv], result);
	}

	if (result == dfs_num[v])
	{
		SCC.emplace_back();
		while (true)
		{
			int t = stk.back(); stk.pop_back();
			SCC.back().push_back(t);
			scc_num[t] = SCC.size() - 1;
			finished[t] = true;
			if (t == v) break;
		}
		sort(SCC.back().begin(), SCC.back().end());
	}
	return result;
}

vector<string> split(string input, char delimiter)
{
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		answer.push_back(temp);
	}

	return answer;
}
void init()
{
	mp.clear();
	name.clear();
	for (int i = 0; i <= n; i++)
	{
		str[i].clear();
		dict[i].clear();
		adj[i].clear();
		in[i] = dfs_num[i] = scc_num[i] = finished[i] = 0;
	}
	for (int i = 0; i < SCC.size(); i++)
	{
		SCC[i].clear();
	}
	SCC.clear();
}
void solve()
{
	name.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		getline(cin, str[i]) ;
	}
	for (int i = 1; i <= n; i++)
	{
		dict[i] = split(str[i], ' ');
		mp[dict[i][0]] = i;
		name[i] = dict[i][0];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < dict[i].size(); j++)
		{
			adj[mp[dict[i][j]]].insert(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfs_num[i]) dfs(i);
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (auto u : adj[i])
		{
			if (scc_num[i] == scc_num[u]) continue;
			// scc_num[i] -> scc_num[u] ==> scc_num[u] ¿« indegree ¡ı∞°
			in[scc_num[u]]++;
		}
	}
	int mx = 200;
	vector<int> ans;
	for (int i = 0; i < SCC.size(); i++)
	{
		for (auto u : SCC[i]) cout << name[u] << " "; cout << "\n";
	}
	for (int i = 0; i < SCC.size(); i++)
	{
		if (in[i] == 0)
		{
			if (mx > SCC[i].size())
			{
				mx = SCC[i].size();
				ans = SCC[i];
			}
		}
	}

	cout << mx << "\n";
	for (auto u : ans) cout << name[u] << " "; cout << "\n";

	init();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> n)
	{
		cin.ignore();
		if (n == 0) break;
		solve();
	}
	return 0;
}


