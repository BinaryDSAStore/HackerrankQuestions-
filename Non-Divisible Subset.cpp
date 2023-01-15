#include <bits/stdc++.h>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s)
{
    vector<int> count(k);
    for (int i : s)
        count[i % k]++;
    int res = min(count[0], 1);
    for (int i = 1; i <= k / 2; i++)
    {
        if (i != k - i)
            res += max(count[i], count[k - i]);
        else
            res++;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    cout << nonDivisibleSubset(k, s) << endl;
    return 0;
}