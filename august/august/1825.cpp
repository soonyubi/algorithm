#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool desc(int a, int b) {
    return a > b;
}
bool incr(int a, int b)
{
    return a < b;
}
int find(vector<int> arr, int inc, int dec) {
    int len = arr.size();
    if (inc - 1 > len - dec || len - dec < 0) {
        return 0;
    }
    vector<int> newArr;
    for (auto x : arr) newArr.push_back(x);

    sort(newArr.begin() + (len - dec), newArr.end(), desc);


    if (inc - 1 == len - dec) {
        for (auto x : newArr) cout << x << ' ';
        return 1;
    }
    else {
        vector<int> nextArr;
        for (int i = 0; i < len - dec; i++) nextArr.push_back(newArr[i]);
        int result = 0;
        for (int i = 2; i <= dec; i++) {
            result = find(nextArr, inc - 1, i);
            if (result) break;
        }
        if (result) {
            for (int i = len - dec; i < len; i++) cout << newArr[i] << ' ';
            return 1;
        }
        else return 0;
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    if (!find(arr, m, k)) cout << -1;
    return 0;
}