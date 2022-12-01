include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
 
const int N = 1000001;
 
int n, m, k;
ll segTree[N * 4];
ll lazy[N * 4]; // Lazy 트리
 
void setLazy(int ptr, int l, int r)
{
    // 현재 원소에 저장된 Lazy 값을 지금 처리해준다.
    ll val = lazy[ptr];
    lazy[ptr] = 0;
 
    segTree[ptr] += (r - l + 1) * val;
 
    if (l != r)
    {
        // 리프노드가 아니라면, 이 값을 또 자식 노드의 Lazy배열로 밀어준다.
        lazy[ptr * 2] += val;
        lazy[ptr * 2 + 1] += val;
    }
}
 
void update(int ptr, int l, int r, int i, int j, ll val)
{
    if (lazy[ptr]) setLazy(ptr, l, r);
    // lazy 트리에 뭔가 저장되어 있다면 지금 처리한다.
 
    if (j < l || r < i) return;
    if (i <= l && r <= j)
    {
        segTree[ptr] += (r - l + 1) * val;
 
        if (l != r)
        {
            // 리프노드가 아니라면, 이 값을 자식 노드의 Lazy배열로 밀어준다.
            lazy[ptr * 2] += val;
            lazy[ptr * 2 + 1] += val;
        }
        return;
    }
 
    update(ptr * 2, l, (l + r) / 2, i, j, val);
    update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j, val);
 
    segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}
 
ll getVal(int ptr, int l, int r, int i, int j)
{
    if (lazy[ptr]) setLazy(ptr, l, r);
    // lazy 트리에 뭔가 저장되어 있다면 지금 처리한다.
 
    if (j < l || r < i) return 0;
    if (i <= l && r <= j) return segTree[ptr];
 
    return getVal(ptr * 2, l, (l + r) / 2, i, j)
        + getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        update(1, 1, n, i, i, x);
    }
 
    for (int i = 0; i < m + k; i++)
    {
        int q; cin >> q;
        if (q == 1)
        {
            ll b, c, d; cin >> b >> c >> d;
            update(1, 1, n, b, c, d);
        }
        else
        {
            ll b, c; cin >> b >> c;
            cout << getVal(1, 1, n, b, c) << '\n';
        }
    }
}
