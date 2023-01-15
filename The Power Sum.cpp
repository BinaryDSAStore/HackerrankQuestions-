#include <bits/stdc++.h>
using namespace std;

int powerSum(int X, int N, int i = 1)
{
    int sum = pow(i, N);
    if (sum > X)
        return 0;
    if (sum == X)
        return 1;
    return powerSum(X, N, i + 1) + powerSum(X - sum, N, i + 1);
}

// int fun(int X, int N, int i)
// {
//     if (X == 0)
//         return 1;
//     int ans = 0;
//     for (int j = i; j <= X; j++)
//     {
//         int sum = pow(j, N);
//         if (sum > X)
//             break;
//         ans += fun(X - sum, N, j + 1);
//     }
//     return ans;
// }

// int powerSum(int X, int N)
// {
//     return fun(X, N, 1);
// }

int main()
{
    int X, N;
    cin >> X >> N;
    cout << powerSum(X, N) << endl;
    return 0;
}
