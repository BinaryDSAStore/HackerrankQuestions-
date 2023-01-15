#include <bits/stdc++.h>
using namespace std;

long funcrec(int n, vector<long> c, long idx, vector<vector<long>> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (idx < 0)
        return 0;

    if (dp[n][idx] != -1)
        return dp[n][idx];

    long take = funcrec(n - c[idx], c, idx, dp);
    long nottake = funcrec(n, c, idx - 1, dp);

    return dp[n][idx] = take + nottake;
}

long getWays(int n, vector<long> c)
{
    long si = c.size();
    vector<vector<long>> dp(n + 1, vector<long>(si, -1));

    return funcrec(n, c, si - 1, dp);
}

int main()
{
    int n{0}, tar{0};
    cin >> tar >> n;
    vector<long> c(n);
    for (int i{0}; i < n; i++)
        cin >> c[i];

    cout << getWays(tar, c);

    return 0;
}
