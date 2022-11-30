/*
dp를 이용해서 O(N^2) 에 모든 팰린드롬을 구할 수 있다.
dp[i][j]가 팰린드롬이라면, j-i+1이 그만큼의 길이이다. 
시간복잡도 O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;

int dp[2500][2500];
string ss;
int isPal(int st,int ed)
{
    int& ret = dp[st][ed];
    if(ret!=-1) return ret;
    if(st>=ed) return 1;
    if(ss[st]!=ss[ed]) return ret = 0;
    return ret = isPal(st+1,ed-1);
}
int solution(string s)
{
    int answer=0;
    ss = s;
    int n = (int)s.size();
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            isPal(i,j);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(dp[i][j])
            {
                answer = max(answer, j-i+1);
            }
        }
    }
   
    return answer;
}
