
/*
*   Time :
*   Subject : Trie
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
struct Trie
{
	map<string, Trie*> child;

	void insert(vector<string> v, int idx)
	{
		if (v.size() == idx) return;
		auto it = child.find(v[idx]);
		if (it == child.end())
		{
			Trie* trie = new Trie();
			child.insert({ v[idx], trie });
			child[v[idx]]->insert(v, idx + 1);
		}
		else
		{
			it->second->insert(v, idx + 1);
		}
	}

	void print(int level)
	{
		if (child.empty()) return;
		for (auto u : child)
		{
			for (int i = 0; i < level; i++) cout << "--";
			cout << u.first << "\n";
			u.second->print(level + 1);
		}
	}

};
void solve()
{
	int n; cin >> n;
	Trie* root = new Trie();
	for (int i = 0; i < n; i++)
	{
		int k; cin >> k;
		vector<string> tmp;
		for (int j = 0; j < k; j++)
		{
			string s; cin >> s;
			tmp.push_back(s);
		}
		root->insert(tmp, 0);
	}
	root->print(0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


