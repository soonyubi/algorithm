#include <bits/stdc++.h>
using namespace std;

struct MCMF {
	int n;
	int c[1010][1010] = { 0 }; //capacity
	int f[1010][1010] = { 0 }; //flow
	int d[1010][1010] = { 0 }; //dist
	vector<int> g[1010]; //graph
	int source, sink;

	MCMF() {
		init(n);
	}

	MCMF(int n, int s, int t) {
		init(n);
		source = s, sink = t;
	}

	void init(int _n) {
		n = _n + 1;
		source = sink = -1;
		memset(c, 0, sizeof c);
		memset(d, 0, sizeof d);
		memset(f, 0, sizeof f);
	}

	void setSource(int s) {
		source = s;
	}

	void setSink(int t) {
		sink = t;
	}

	void addEdge(int s, int e, int cap, int dist) {
		g[s].push_back(e); c[s][e] = cap; d[s][e] = dist;
		g[e].push_back(s); c[e][s] = 0; d[e][s] = -dist;
	}

	int mcmf() {
		int cnt = 0;
		int minCost = 0;
		int prv[1010], dist[1010];
		bool inque[1010] = { 0 };
		while (1) {
			memset(prv, -1, sizeof prv); memset(dist, 0x3f, sizeof dist); memset(inque, 0, sizeof inque);
			queue<int> q;
			dist[source] = 0;
			inque[source] = 1;
			q.push(source);

			while (q.size()) {
				int now = q.front(); q.pop(); inque[now] = 0;
				for (auto nxt : g[now]) {
					if (c[now][nxt] - f[now][nxt] > 0 && dist[nxt] > dist[now] + d[now][nxt]) {
						dist[nxt] = dist[now] + d[now][nxt];
						prv[nxt] = now;
						if (!inque[nxt]) {
							q.push(nxt);
							inque[nxt] = 1;
						}
					}
				}
			}
			if (prv[sink] == -1) break;
			int flow = 1e9 + 7;
			for (int i = sink; i != source; i = prv[i]) {
				flow = min(flow, c[prv[i]][i] - f[prv[i]][i]);
			}
			for (int i = sink; i != source; i = prv[i]) {
				c
				minCost += flow * d[prv[i]][i];
				f[prv[i]][i] += flow;
				f[i][prv[i]] -= flow;
			}
			cnt++;
		}
		cout << cnt << "\n";
		return minCost;
	}
};
MCMF flow(1002,1001,1002);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	

	//cout << "init\n";

	for (int i = 1; i <= n; i++) {
		flow.addEdge(1001, i, 1, 0);
	}
	for (int i = 501; i <= 500 + m; i++) {
		flow.addEdge(i, 1002, 1, 0);
	}

	for (int i = 1; i <= n; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int a, b; cin >> a >> b;
			flow.addEdge(i, 500 + a, 1, b);
		}
	}

	cout << flow.mcmf();
}