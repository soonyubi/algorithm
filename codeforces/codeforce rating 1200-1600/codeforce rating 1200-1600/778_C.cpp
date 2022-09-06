
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

vector<ll> v;
bool go(ll sum)
{
	if (sum == 0) return false;
	if (!v.empty())
	{
		if (v.back() == sum)
		{
			v.pop_back();
			return true;
		}
		if (v.back() > sum)
		{
			cout << v.back() << " " << sum << "\n";
			return false;
		}
	}
	
	ll sum1, sum2;
	if (sum % 2 == 0)
	{
		sum1 = sum2 = sum / 2;
	}
	else
	{
		sum1 = sum / 2 + 1;
		sum2 = sum / 2;
	}
	bool ret1 = go(sum1);
	bool ret2 = go(sum2);
	if (ret1 && ret2) return true;
	return false;
}
void solve()
{
	int n; cin >> n;
	v.resize(n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	
	sort(v.begin(), v.end());
	//cout << sum << "\n";
	priority_queue<ll> q;
	q.push(sum);

	while (!q.empty())
	{
		ll s = q.top();
		q.pop();
		if (!v.empty())
		{
			if (v.back() == s)
			{
				v.pop_back();
				continue;
			}
			else if(v.back()>s)
			{
				cout << "NO\n";
				return;
			}
		}
		if (v.empty())
		{
			cout << "YES\n";
			return;
		}
		ll s1, s2;
		if (s % 2 == 1)
		{
			s1 = s / 2 + 1;
			s2 = s / 2;
			
		}
		else
		{
			s1 = s / 2;
			s2 = s / 2;
		}
		if (s1 != 0) q.push(s1);
		if (s2 != 0) q.push(s2);
		
	}
	if (v.empty())
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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


