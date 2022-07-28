

/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/
/*
O(N^3X) 시간복잡도 풀이 = O(N^2) 버블정렬 , O(NX) : N개의 수를 각 X에 대치

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<int, int>
#define pll pair<ll, ll>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN

using namespace std;
const int inf = 1e9;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve()
{
	int n; cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	vector<int> ans(n + 1, inf);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 200; j++)
		{
			int tmp = v[i];
			v[i] = j;
			int cnt = 0;
			for (int k = 1; k <= n; k++)
			{
				for (int l = k + 1; l <= n; l++)
				{
					if (v[k] > v[l]) cnt++;
				}
			}
			v[i] = tmp;
			ans[i] = min(ans[i], cnt);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}cout << "\n";
}
int main()
{
	
	solve();
	return 0;
}

*/



/*
*   Time :
*   Subject : O(NXlog(X)) 
	i>j 중 A[j] > A[i]를 만족하는 원소의 갯수를 count
	i<k 중 A[k] < A[i]를 만족하는 원소의 갯수를 count
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

const int maxn = 3000;
const ll inf = 1e9;
vector<ll> segTree;
void update(int ptr, int s, int e, int i, ll diff)
{
	if (s > i || e < i) return;
	segTree[ptr] += diff;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(ptr * 2, s, mid, i, diff);
	update(ptr * 2 + 1, mid + 1, e, i, diff);
}
ll query(int ptr, int s, int e, int l, int r)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return segTree[ptr];
	int mid = (s + e) / 2;
	return query(ptr * 2, s, mid, l, r) + query(ptr * 2 + 1, mid + 1, e, l, r);
}
void solve()
{
	int n; cin >> n;
	segTree.resize(4*maxn);
	vector<pll> v(n);
	vector<pll> arr(n + 1);
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		v[i] = { x,i };
		
	}
	sort(v.begin(), v.end());

	ll ans = 0;
	vector<ll> ans_arr(n + 1, ans);
	for (int i = 1; i <= n; i++)
	{
		ll x = v[i-1].second;
		ans += query(1, 1, maxn, x + 1, maxn);
		for (int j = 0; j <= maxn; j++)
		{
			ll y1 = query(1, 1, maxn, 1, j - 1);
			ll y2 = query(1, 1, maxn, j + 1, maxn);
			ans_arr[i] = min(ans_arr[i], y1 + y2);
		}
		update(1, 1, maxn, x, 1);
	}

	for (int i = 1; i <= n; i++)
	{
		ll x = v[i - 1].second;
		update(1, 1, maxn, x, -1);
		
		update(1, 1, maxn, x, 1);
	}
	for (int i = 1; i <= n; i++) cout << ans_arr[i] << " "; cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


