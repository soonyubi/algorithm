
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

int par[100001];
ll height[100001]; // ���� ���տ� ���� ������ ���� 
int getPar(int a)
{
	if (par[a] == -1) return a;
	else return par[a] = getPar(par[a]);
}
ll merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);
	if (a == b) return 0;
	ll cnt1 = height[a]; // a�� ���� ������ ���� ����
	ll cnt2 = height[b]; // b�� ���� ������ ���� ����
	if (a < b)
	{
		height[a] += height[b];
		par[b] = a;
		
	}
	else
	{
		height[b] += height[a];
		par[a] = b;
	}
	return cnt1 * cnt2;
}
void solve()
{
	int n, m, q; cin >> n >> m >> q;
	vector<pii> v(m + 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<int> cut;
	vector<bool> chk(m + 1, true);
	for (int i = 0; i < q; i++)
	{
		int x; cin >> x;
		cut.push_back(x);
		chk[x] = false;
	}
	memset(par, -1, sizeof(par));
	for (int i = 1; i <= n; i++) height[i] = 1;
	
	for (int i = 1; i <= m; i++)
	{
		if (chk[i])
		{
			// �� ������ ������ѳ���
			int a = v[i].first;
			int b = v[i].second;
			merge(a, b);
		}
	}
	ll ans = 0;
	while (!cut.empty())
	{
		int x = cut.back(); 
		cut.pop_back();

		// x �ε����� �ش��ϴ� ������ �����Ű�µ� 
		// ���� �����̸�, 0, �ٸ� �����̸� ���� ���տ� ���� ������ ���� ��
		int a = v[x].first;
		int b = v[x].second;
		ll tmp = merge(a, b);
		ans += tmp;
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


