/* ~p->q */


#include <bits/stdc++.h>
using namespace std;

vector<int> gph[20202], rev[20202];

inline int notX(int x){ return x ^ 1; }
inline int trueX(int x){ return x << 1; }
inline int falseX(int x){ return x << 1 | 1; }

int visit[20202];
vector<int> dfn;
int scc[20202];

void dfs(int v){
	visit[v] = 1;
	for(auto u : gph[v]) if(!visit[u]) dfs(u);
	dfn.push_back(v);
}

void revdfs(int v, int color){
	visit[v] = 1;
	scc[v] = color;
	for(auto u : rev[v]) if(!visit[u]) revdfs(u, color);
}

void getSCC(int n){
	memset(visit, 0, sizeof visit);
	for(int i=1*2; i<=n*2+1; i++){
		if(!visit[i]) dfs(i);
	}
	memset(visit, 0, sizeof visit);
	reverse(dfn.begin(), dfn.end());
	int cnt = 1;
	for(auto i : dfn){
		if(!visit[i]){
			revdfs(i, cnt); cnt++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		if(a > 0) a = trueX(a);
		else a = falseX(-a);
		if(b > 0) b = trueX(b);
		else b = falseX(-b);

		gph[notX(a)].push_back(b);
		gph[notX(b)].push_back(a);
		rev[b].push_back(notX(a));
		rev[a].push_back(notX(b));
	}

	getSCC(n);

	for(int i=1; i<=n; i++){
		if(scc[trueX(i)] == scc[falseX(i)]){
			cout << "0"; return 0;
		}
	}
	cout << "1";
}
