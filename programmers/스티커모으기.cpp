/*
0번째 인덱스를 제거하면 n-1번째 인덱스는 무조건 제거되면 안된다. 

0번째 인덱스를 제거하면 n-1번째 인덱스는 제거되거나 제거되지 않아도 된다. 

dp[n][0] = max( dp[n-1][0], dp[n-1][1] ) // 현재 인덱스 제거 x 
dp[n][1] = max( dp[n-1][0] + v[n] ) // 현재 인덱스 제거 

*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;
int dp[maxn][2];

int solution(vector<int> sticker)
{
    int answer =0;
    
    int n = sticker.size();
    if(n==1) 
    {
        return sticker[0];
    }
    // 첫번째 뜯을 때 
    memset(dp,0,sizeof(dp));
    dp[0][1] = sticker[0];
    for(int i=1;i<n;i++)
    {
        dp[i][0] = max(dp[i-1][0],dp[i][0]);
        dp[i][0] = max(dp[i-1][1],dp[i][0]);
        dp[i][1] = max(dp[i-1][0] + sticker[i],dp[i][1]);
    }
    answer = max(answer,dp[n-1][0]);
    // 첫번째 안 뜯을 때
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n;i++)
    {
        dp[i][0] = max(dp[i-1][0],dp[i][0]);
        dp[i][0] = max(dp[i-1][1],dp[i][0]);
        dp[i][1] = max(dp[i-1][0] + sticker[i],dp[i][1]);
    }
    answer = max(answer,dp[n-1][0]);
    answer = max(answer,dp[n-1][1]);
    return answer;
}
