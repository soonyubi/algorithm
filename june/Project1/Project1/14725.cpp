
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

struct Trie
{
	map<string, Trie*> child;
	map<string, Trie*>::iterator iter;

	void insert(vector<string> v, int idx)
	{
		if (idx == v.size()) return;
		iter = child.find(v[idx]);
		if (iter != child.end())
		{
			iter->second->insert(v, idx + 1);
		}
		else
		{
			Trie* new_trie = new Trie;
			child.insert({v[idx],new_trie});
			new_trie->insert(v, idx + 1);
		}
	}

	void print(int idx)
	{
		for (auto it = child.begin(); it != child.end(); it++)
		{
			for (int i = 0; i < idx; i++)
			{
				cout << "--";
			}
			cout << it->first << "\n";
			it->second->print(idx + 1);
		}
	}
};

void solve()
{
	int n; cin >> n;
	Trie* trie = new Trie;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		string ss;
		vector<string> v;
		for (int j = 0; j < x; j++)
		{
			cin >> ss; v.push_back(ss);
		}
		trie->insert(v, 0);
	}
	trie->print(0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


