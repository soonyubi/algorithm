typedef pair<int, int> p;

const int inf = 1e9+7;

class FordFulkerson{
	private:
		vector< vector<int> > flow, capacity, adjList;
		int s, e, n; //source, sink, verties
	public:
		FordFulkerson(){ n = 0, s = -1, e = -1; }
		FordFulkerson(int n){
			this->n = n;
			flow.resize(n+1), capacity.resize(n+1), adjList.resize(n+1);
			for(int i=0; i<=n; i++){
				flow[i].resize(n+1);
				capacity[i].resize(n+1);
			}
			s = -1, e = -1;
		}
		FordFulkerson(int n, int source, int sink){
			this->n = n;
			flow.resize(n+1), capacity.resize(n+1), adjList.resize(n+1);
			for(int i=0; i<=n; i++){
				flow[i].resize(n+1);
				capacity[i].resize(n+1);
			}
			s = source, e = sink;
		}
		void setSource(int t){ s = t; }
		void setSink(int t){ e = t; }
		void addEdge(int start, int end, int cap, bool directed){
			adjList[start].push_back(end);
			adjList[end].push_back(start);
			capacity[start][end] += cap;
			if(!directed) capacity[end][start] += cap;
		}

		int maxFlow(){
			if(s==-1 || e==-1) return -1;
			vector<int> par(n+1);
			queue<int> q;
			int ret = 0;
			while(1){
				fill(par.begin(), par.end(), -1);
				q = queue<int>(); q.push(s);
				while(!q.empty()){
					int now = q.front(); q.pop();
					for(auto nxt : adjList[now]){
						if(par[nxt] == -1 && capacity[now][nxt]-flow[now][nxt] > 0){
							q.push(nxt); par[nxt] = now;
							if(nxt == e) break;
						}
					}
				}
				if(par[e] == -1) break;
				int cost = inf;
				for(int i=e; i!=s; i = par[i]){
					int a = par[i], b = i;
					cost = min(cost, capacity[a][b] - flow[a][b]);
				}
				ret += cost;
				for(int i=e; i!=s; i = par[i]){
					int a = par[i], b = i;
					flow[a][b] += cost; flow[b][a] -= cost;
				}
			}
			return ret;
		}
};
