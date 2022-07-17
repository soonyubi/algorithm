
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
bool ans;
struct Trie
{
	Trie* go[10];
	bool output; // 현재까지 번호가 끝인 경우
	int branch; // 현재 번호에서 나아갈 수 있는 갯수
	int num; // 현재 번호에서 나아갈 수 있는 총 전화번호의 갯수

	Trie() :output(false), branch(0), num(0)
	{
		fill(go, go + 10, nullptr);
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++)
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
			if (!go[*str - '0'])
			{
				go[*str - '0'] = new Trie;
				branch++;
			}
			num++;
			go[*str - '0']->insert(str + 1);
		}
	}

	void consistent()
	{
		
		if (output)
		{
			if (branch > 1) { ans = false; return; }
			return;
		}

		for (int i = 0; i < 10; i++)
		{
			if(go[i]) go[i]->consistent();
		}
		
	}
};

void solve()
{
	int n; cin >> n;
	Trie* root = new Trie;
	for (int i = 0; i < n; i++)
	{
		char phone[11];
		cin >> phone;
		root->insert(phone);
	}
	ans = true;
	root->consistent();
	if (ans) cout << "YES\n";
	else cout << "NO\n";
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


