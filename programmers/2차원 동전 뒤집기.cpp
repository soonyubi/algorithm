/*
  완전 탐색 문제 
  row, column 을 두번이상 바꾸는 경우 이전 상태와 동일하므로 
  row, column을 최대 한번 바꾸는 경우의 수만 세주면 됌. 
  
  시간복잡도 : O(2^(n+m)*nm)) 
*/

#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 1e9+7;
    int n,m; 
    n = beginning.size();
    m = beginning[0].size();
    vector<vector<int>> temp = beginning;
    
    for(int i=0;i<(1<<(n+m));i++)
    {
        
        int cur_cnt =0;
        // row : n
        for(int j=0;j<n;j++)
        {
            if(i&(1<<(j)))
            {
                cur_cnt++;
                for(int k=0;k<m;k++)
                {
                    temp[j][k] = (temp[j][k]==1?0:1);
                }
            }
        }
        // col : m
        for(int j=0;j<m;j++)
        {
            if(i&(1<<(n+j)))
            {
                cur_cnt++;
                for(int k=0;k<n;k++)
                {
                    temp[k][j] = (temp[k][j]==1?0:1);
                }
            }
        }
        
        
        bool flag = true;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(temp[j][k]!=target[j][k]) flag = false;
                temp[j][k] = beginning[j][k];
            }
        }
       
        if(flag) answer = min(answer,cur_cnt);
        
    }
    
    if(answer == 1e9+7) answer= -1;
    return answer;
}
