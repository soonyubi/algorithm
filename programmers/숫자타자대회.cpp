/*

dp[idx][l][r] => idx 번째에 왼손으로 l을 누르고 오른손으로 r을 눌렀을 경우의 값 

현재 눌러야 할 값을 cur라 할때, cur == left 인지 cur == right인지 구분해야함 

위 상황 모두 아니라면, cur을 왼손으로 누를지 오른손으로 누를지 결정해야됨 

*/

#include <bits/stdc++.h>
using namespace std;
int sz;
string s;
const int maxn = 1e5+1;
const int dist[10][10] = {
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};
int dp[maxn][10][10];

int go(int idx,int left,int right)
{
    if(idx==sz)
    {
        return 0;
    }
    
    int& ret = dp[idx][left][right];
    if(ret!=-1) return ret;
    ret = 0;
    int cur = s[idx] -'0';
    
    if(left==cur)
    {
        return ret = go(idx+1,cur,right) +1;
    }
    if(right == cur)
    {
        return ret = go(idx+1,left,cur) +1;    
    }
    return ret = min(go(idx+1,cur,right)+dist[left][cur],go(idx+1,left,cur)+dist[right][cur]);
}
int solution(string numbers) {
    int answer = 0;
    s= numbers;
    sz = (int)numbers.size();
    memset(dp,-1,sizeof(dp));
    answer= go(0,4,6);
    return answer;
}
