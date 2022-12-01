/* Kosaraju */
	
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
 
int v, e;
vector <int> graph[10001];
 
vector<vector<int> > SCC;
 
int DFS_cnt = 1;
int DFS_num[10001];
int DFS_min[10001];
int cache[10001];
vector <int> stk;
void DFS(int v)
{
    cache[v] = 1;
    DFS_num[v] = DFS_min[v] = DFS_cnt++;
    stk.push_back(v);
    for (int nv : graph[v])
    {
        if (!DFS_num[nv]) DFS(nv);
        if (cache[nv]) DFS_min[v] = min(DFS_min[v], DFS_min[nv]);
    }
 
    if (DFS_num[v] == DFS_min[v])
    {
        SCC.emplace_back();
        while (true)
        {
            int tv = stk.back();
            SCC.back().push_back(tv);
            cache[tv] = 0;
            stk.pop_back();
 
            if (tv == v) break;
        }
 
 
        sort(SCC.back().begin(), SCC.back().end());
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }
 
    for (int i = 1; i <= v; i++)
    {
        if (!DFS_num[i]) DFS(i);
    }
 
    sort(SCC.begin(), SCC.end());
 
    cout << SCC.size() << '\n';
    for (auto& it : SCC)
    {
        for (int v : it) cout << v << ' ';
        cout << "-1\n";
    }
}
