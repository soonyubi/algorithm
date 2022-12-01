/*회전하는 캘리퍼스 */ 


#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
 
pll p2v(pll a, pll b) // 두 점 A,B가 주어지면 벡터 AB를 반환
{
    return { b.first - a.first, b.second - a.second };
}
 
ll ccw(pll v1, pll v2) // 벡터 v1, v2의 CCW
{
    ll res = v1.first * v2.second - v1.second * v2.first;
 
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}
 
ll dist2(pll a, pll b) // 점 A,B사이의 거리의 제곱
{
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}
 
int n;
pii point[200001];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> point[i].first >> point[i].second;
            if (point[i] < point[0]) swap(point[0], point[i]);
        }
 
        sort(point + 1, point + n, [](pii a, pii b) {
            // 각도순 정렬
            pll v1 = p2v(point[0], a);
            pll v2 = p2v(point[0], b);
            ll res = ccw(v1, v2);
 
            if (res) return res > 0;
            return dist2(point[0], a) < dist2(point[0], b);
            // 세 점이 일직선에 있다면 거리 순으로 정렬
            });
 
        vector <pll> CH;
 
        for (int i = 0; i < n; i++)
        {
            while (CH.size() > 1)
            {
                pll p1 = CH[CH.size() - 2];
                pll p2 = CH[CH.size() - 1];
                pll p3 = point[i];
 
                pll v1 = p2v(p1, p2);
                pll v2 = p2v(p2, p3);
 
                ll res = ccw(v1, v2);
                if (res > 0) break;
 
                CH.pop_back();
            }
 
            CH.push_back(point[i]);
        }
 
        int i1 = min_element(CH.begin(), CH.end()) - CH.begin();
        int i2 = max_element(CH.begin(), CH.end()) - CH.begin();
        // 기준점 2개를 잡는다
 
        ll mxDist = 0;
        int ans1 = -1, ans2 = -1;
 
        for (int i = 0; i < CH.size(); i++)
        {
            pll p1 = CH[i1], p1_nxt = CH[(i1 + 1) % CH.size()];
            pll p2 = CH[i2], p2_nxt = CH[(i2 + 1) % CH.size()];
 
            ll curDist = dist2(p1, p2);
            if (curDist > mxDist)
            {
                mxDist = curDist;
                ans1 = i1, ans2 = i2;
            }
 
            pll v1 = p2v(p1, p1_nxt);
            pll v2 = p2v(p2_nxt, p2);
 
            if (ccw(v1, v2) > 0) i1 = (i1 + 1) % CH.size();
            else i2 = (i2 + 1) % CH.size();
            // 더 각도가 작은 쪽으로 캘리퍼스 회전
        }
 
        cout << CH[ans1].first << ' ' << CH[ans1].second << ' '
            << CH[ans2].first << ' ' << CH[ans2].second << '\n';
    }
}
