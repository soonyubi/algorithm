/*
가중치가 1인 최단거리 구하기 문제이므로 bfs 

*/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;
vector<int> adj[maxn];
bool visited[maxn];
int dist[maxn];
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(auto r : roads)
    {
        int u = r[0],v=r[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(dist,-1,sizeof(dist));
    
    queue<int> q;
    q.push(destination);
    visited[destination] = true;
    dist[destination] = 0;
    
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        
        for(auto nv : adj[v])
        {
            if(!visited[nv])
            {
                visited[nv] = true;
                dist[nv] = dist[v] +1;
                q.push(nv);
            }
        }
    }
    
    for(auto u : sources)
    {
        answer.push_back(dist[u]);
    }
        
    
    return answer;
}
