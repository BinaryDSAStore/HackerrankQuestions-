#include <bits/stdc++.h>
using namespace std;

int lonelyinteger(vector<int> a)
{
    int res = 0;
    for (int i : a)
        res ^= i;
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << lonelyinteger(a) << endl;
    return 0;
}