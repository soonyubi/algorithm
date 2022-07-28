
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

struct Trie
{
	Trie* go[26];
	bool output;

	Trie()
	{
		fill(go, go + 26, nullptr);
		output = false;
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++) if (go[i]) delete go[i];
	}

	void insert(const char* str)
	{
		if (*str == '\0')
		{
			output = true;
			return;
		}
		int idx = *str - 'a';
		if (!go[idx])go[idx] = new Trie();
		go[idx]->insert(str + 1);
		return;
	}

	bool check(const char* str)
	{
		if (*str == '\0') {
			return output;
		}
		int idx = *str - 'a';
		if (!go[idx]) return false;
		return go[idx]->check(str + 1);

		
	}
};
void solve()
{
	int n, m; cin >> n >> m;
	Trie* root = new Trie();
	for (int i = 0; i < n; i++)
	{
		//string s; cin >> s;
		char s[501]; cin >> s;
		root->insert(s);
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		//string s; cin >> s;
		char s[501]; cin >> s;
		if (root->check(s)) ans++;
	}
	cout << ans << "\n";
	
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	solve();
	return 0;
}


