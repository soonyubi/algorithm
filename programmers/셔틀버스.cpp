/*
구현 + 그리디 

일단 시간과 관련된 문자열을 초단위의 정수로 바꾼다. 

그리고 콘이 나오는 시간을 0~3599 까지 반복하면서 우선순위 큐에 넣어준다. 
이때 콘과 같은 시간에 나온 다른 크루의 우선순위가 더 높다는 것을 인지한다. 

문제가 요구하는대로 구현하면 된다. 

N : 3600 / K : Timetable의 사이즈 

시간복잡도 : O(NK + Nnm) == O(NK) 

*/

#include <bits/stdc++.h>
using namespace std;
struct cmp
{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        if(a.first==b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int ans = 0;
    for(int i=0;i<3600;i++)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        pq.push({i,1});
        for(auto u : timetable) 
        {
            int t = ((u[0]-'0')*10 + (u[1]-'0'))*60 + ((u[3]-'0')*10 + (u[4]-'0'));
            pq.push({t,0});
        }
        
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m && !pq.empty();k++)
            {
                int time = pq.top().first;
                int flag = pq.top().second;
                if(time <= j*t+540)
                {
                    pq.pop();
                    if(flag)
                    {
                        ans= max(ans,time);
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    int q = ans/60;
    int r = ans%60;
    
    if(q<10){ answer += "0"; answer += to_string(q);}
    else answer += to_string(q);
    answer+=":";
    if(r<10){ answer += "0"; answer += to_string(r);}
    else answer += to_string(r);
    
    return answer;
}
