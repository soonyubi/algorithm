/*
 row : 0 일 때 몇 번 바꿀지를 미리 결정한다. 
 ex) [0,0,0,0] [0,0,0,1] .... [3,3,3,3] 
 
 row: 1~n-1 을 살펴보면서 바로 윗행을 몇번 바꿔야 될지 보고 그만큼만 바꾼다. 
 
 답이 되는지 확인하려면 마지막 row 가 모두 0인지 확인한다. 
 
 시간복잡도 : O(4^(2*n) * (n^2)) 

*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;
int n;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

bool isRange(int y,int x)
{
    if(y>=0&&y<n&&x>=0&&x<n) return true;
    return false;
}

int go(vector<vector<int>> v, vector<int> rotate)
{
    int res= 0;
    
    for(int i=0;i<n;i++)
    {
        res += rotate[i];
        v[0][i] = (v[0][i]+rotate[i])%4;
        for(int k =0;k<4;k++)
        {
            int ny= dy[k];
            int nx= dx[k]+i;
            if(!isRange(ny,nx)) continue;
            v[ny][nx] = (v[ny][nx] + rotate[i])%4;
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i-1][j]==0) continue;
            int to = 4 -v[i-1][j];
            res+=to;
            v[i][j] = (v[i][j] +to)%4;
            for(int k=0;k<4;k++)
            {
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                if(!isRange(ny,nx)) continue;
                v[ny][nx] = (v[ny][nx] + to)%4;
            }
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(v[n-1][i]!=0) res=inf;
    }
    
    if(res!=inf)
    {
        for(int i=0;i<n;i++) cout << rotate[i]<<" ";cout << res <<" ";cout <<"\n";
    }
    return res;
}

int solution(vector<vector<int>> clockHands) {
    int answer = inf;
    n = (int)clockHands.size();
    vector<int> rotate(n,0);
    
    for(int i=0;i<(1<<(2*n));i++)
    {
        for(int j=0;j<n;j++)
        {
            int r =0;
            if(i&(1<<(2*j))) r+= 1;
            if(i&(1<<(2*j+1))) r+=2;
            rotate[j] = r;
            
            
        }
        int temp = go(clockHands,rotate);
        answer = min(answer, temp);
    }
    
    
    return answer;
}
