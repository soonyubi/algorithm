/*
완전 탐색 문제인데 dp를 곁들인 
각 보드의 상태마다 4가지 방향으로 갈 수 있다
이때 상태를 dp[y][x][dir]이라 한다면 그 값이 의미하는 바는 y,x에서 dir방향으로 갈때 비용이다. 
bfs로 풀면 상당히 쉽지만, dfs 로 풀면 bfs 로 푼것과 다르게 생각해야 하므로 조금 바꿔줘야 할게 많다. 
*/


/*BFS 풀이*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

const int inf = 1e9+7;
int n;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int dp[33][33][4];
bool isRange(int y,int x)
{
    if(y>=0&&y<n&&x>=0&&x<n) return true;
    return false;
}
int solution(vector<vector<int>> board) {
    int answer = inf;
    n = board.size();
    memset(dp,inf,sizeof(dp));
    queue<pair<pii,int>> q;
    q.push({{0,0},0});
    q.push({{0,0},1});
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    
    while(!q.empty())
    {
        int y= q.front().first.first;
        int x= q.front().first.second;
        int dir = q.front().second;
        q.pop();
        if(y==n-1&&x==n-1)
        {
            answer= min(dp[y][x][dir],answer);
        }
        bool flag1 = (dir%2==0);
        bool corner;
        for(int i=0;i<4;i++)
        {
            bool flag2 = (i%2==0);
            if((flag1&&flag2)||(!flag1&&!flag2)) corner = false;
            else corner = true;
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            int nc = dp[y][x][dir] + 100 + (corner?500:0);
            
            if(!isRange(ny,nx)) continue;
            if(board[ny][nx]==1) continue;
            if(dp[ny][nx][i] < nc) continue;
            dp[ny][nx][i] = nc;
            q.push({{ny,nx},i});
        }
    }
    // answer = min(dp[n-1][n-2][1],dp[n-2][n-1][0]);
    return answer;
}
