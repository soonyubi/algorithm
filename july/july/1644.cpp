
/*
*   Time :
*   Subject : two pointer 
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

const int MAX = 4000000;
int n;
bool isPrime[MAX + 1];
vector<int> prime;
void getPrime()
{
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j * i <= n; j++)
		{
			if (j * i > n) continue;
			isPrime[j * i] = false;
			
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i]) prime.push_back(i);
	}
	
	
}
void solve()
{
	cin >> n;
	getPrime();
	vector<int> psum(prime.size() + 1, 0);
	for (int i = 1; i <= prime.size(); i++)
	{
		psum[i] = psum[i - 1] + prime[i - 1];
	}

	int i = 0, j = 0, ans=0;
	while (i <= j && j < psum.size())
	{
		int x = psum[j] - psum[i];
		if (x > n)
		{
			i++;
		}
		else if (x < n)
		{
			j++;
		}
		else
		{
			ans++; 
			j++;
		}

	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


