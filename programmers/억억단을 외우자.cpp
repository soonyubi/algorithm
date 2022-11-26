/*
[s,e] 사이의 약수 갯수 중 가장 많은 것 중 그 수가 가장 작은 것의 갯수를 구하는 문제 

5e5 까지 수 중 약수의 갯수중 가장 큰 것이 384개 이므로 

384~1 를 약수의 갯수로 가지는 것들 중 [s,e] 사이에 속하는 가장 작은 수를 구하면 된다. 

시간복잡도 : O(nlog(k)) : n<=1e5, k<=5e5 

*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000001;
int dp[maxn];
vector<int> v[400];

void go()
{
    for(int i=1;i<maxn;i++)
    {
        for(int j=1;j*i<maxn;j++)
        {
            dp[i*j]++;
        }
    }
    for(int i=1;i<maxn;i++)
    {
        v[dp[i]].push_back(i);
    }
    // cout << *max_element(dp,dp+maxn) <<"\n";
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    go();
    
    for(auto u : starts)
    {
        for(int i=384;i>=1;i--)
        {
            auto it = lower_bound(v[i].begin(),v[i].end(),u);
            if(it!=v[i].end() && *it<=e)
            {
                answer.push_back(*it);
                break;
            }
        }
    }
    
    return answer;
}
