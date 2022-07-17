
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
	int branch; // 자식노드의 갯수
	int words; // 현재 단어까지에서 나아갈 수 있는 단어의 총 갯수

	Trie() :output(false), branch(0), words(0) { fill(go, go + 26, nullptr); };
	~Trie() {
		for (int i = 0; i < 26; i++)
		{
			if (go[i]) delete go[i];
		}
	}

	void insert(char* str)
	{
		if (*str == '\0')
		{
			branch++;
			output = true;
		}
		else
		{
			if (!go[*str - 'a'])
			{
				++branch;
				go[*str - 'a'] = new Trie;
			}
			words++;
			go[*str - 'a']->insert(str + 1);
		}
	}

	ll cntKeyStroke(bool isRoot=false)
	{
		ll result = 0;

		if (isRoot || branch > 1) result += words;

		for (int i = 0; i < 26; i++)
		{
			if (go[i]) result += go[i]->cntKeyStroke();
		}
		return result;
	}
};

void solve()
{
	int n; 
	while (cin >> n)
	{
		if (n <= 0) break;
		Trie* root = new Trie;
		for (int i = 0; i < n; i++)
		{
			char w[81];
			cin >> w;
			root->insert(w);

		}
		cout << fixed;
		cout.precision(2);
		cout << (root->cntKeyStroke(true) * 1.0 / n) << "\n";
		delete root;
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


