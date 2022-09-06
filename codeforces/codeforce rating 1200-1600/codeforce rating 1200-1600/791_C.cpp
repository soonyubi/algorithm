
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

const int maxn = 1e5;
vector<ll> row;
vector<ll>column;
void update1(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	row[ptr] += val;
	if (s == e) return;
	int mid = (s + e) / 2;
	update1(ptr * 2, s, mid, i, val);
	update1(ptr * 2 + 1, mid + 1, e, i, val);
}
void update2(int ptr, int s, int e, int i, ll val)
{
	if (s > i || e < i) return;
	column[ptr] += val;
	if (s == e) return;
	int mid = (s + e) / 2;
	update2(ptr * 2, s, mid, i, val);
	update2(ptr * 2 + 1, mid + 1, e, i, val);
}
ll query1(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return row[ptr];
	int mid = (s + e) / 2;
	return query1(ptr * 2, s, mid, l, r) + query1(ptr * 2 + 1, mid + 1, e, l, r);
}
ll query2(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return column[ptr];
	int mid = (s + e) / 2;
	return query2(ptr * 2, s, mid, l, r) + query2(ptr * 2 + 1, mid + 1, e, l, r);
}
int currow[maxn + 1]; // ���� row�� ������ ���� �����ϴ� column����
int curcol[maxn + 1]; // ���� column�� ������ ���� �����ϴ� row ����

void solve()
{
	int n, q; cin >> n >> q;
	row = vector<ll>(maxn * 4 + 10);
	column = vector<ll>(maxn * 4 + 10);
	for (int i = 0; i < q; i++)
	{
		int op; cin >> op;
		if (op == 1)
		{
			int r, c; cin >> r >> c;
			/*
			if (currow[r] != 0) // ���� r�࿡ ������ ���� �����ϴ� ���� �����Ѵٸ�
			{
				update2(1, 1, n, currow[r], -1); // �ش� ���� �����ϴ� �� ����
				
			}
			currow[r] = c;  // r�࿡ ������ ���� �����ϴ� �� ����
			if (curcol[c] != 0) // ���� c���� ������ ���� �����ϴ� ���� �����Ѵٸ�
			{
				update1(1, 1, n, currow[c], -1); // �ش� �࿡ �����ϴ� �� ����
			}
			curcol[c] = r; // c���� ������ ���� �����ϴ� �� ����
			*/
			if(!currow[r]) update1(1, 1, n, r, 1); 
			if(!curcol[c]) update2(1, 1, n, c, 1);
			currow[r]++;
			curcol[c]++;
		}
		else if (op == 2)
		{
			int r, c; cin >> r >> c;
			currow[r]--;
			curcol[c]--;
			if (!currow[r]) update1(1, 1, n, r, -1);
			if (!curcol[c]) update2(1, 1, n, c, -1);
			
		}
		else
		{
			int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
			if (query1(1, 1, n, r1, r2) == r2 - r1 + 1) cout << "YES\n";
			else if (query2(1, 1, n, c1, c2) == c2 - c1 + 1) cout << "YES\n";
			else cout << "NO\n";
		}
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


