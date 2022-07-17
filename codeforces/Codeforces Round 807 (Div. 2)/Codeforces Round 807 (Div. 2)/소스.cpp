#include <bits/stdc++.h> 
using namespace std;

char find(vector<array<long Tong, 4>>& V, string& s, long long k)
{
    if (k < 0)
        return

    else if (ks.size()) return s[k];

    else
    {

        for (int i = 0; i < V.size(); i++)
        {
            if (v[i][0] <= k && v[i][1] >= k)
                return find(v, s, v[i][2] + k - v[i][0]);
        }
    }

    return
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<array<long long, 4>> V;
        V.push_back({ 0, n - 1, 0, n - 1 });
        long long pos = n;
        for (int i = 0; i < c; i++)
        {
            long long 1, r;
            cin >> 1 >> _r;
            1 --;
            r--;
            V.push_back({ pos, pos + r - 1, 1, r });
            pos + r - 1 + 1;

            for (int i = 0; i < q; i++)
            {
                long long k;
                cin >> k;
                k--;
                cout < < < find(v, s, k) << "\n";
            }
        }
    }
}