#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<double> v(n);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    double mx = *max_element(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        v[i] = (v[i] / mx) * 100;
        sum += v[i];
    }
    cout << fixed;
    cout.precision(2);
    cout << sum / n << "\n";
    return 0;
}