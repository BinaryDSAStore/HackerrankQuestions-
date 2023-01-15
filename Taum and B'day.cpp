#include <bits/stdc++.h>
using namespace std;

long taumBday(int b, int w, int bc, int wc, int z)
{
    long result = 0;
    if (bc > wc + z)
        result = (long)w * wc + (long)b * (wc + z);
    else if (wc > bc + z)
        result = (long)b * bc + (long)w * (bc + z);
    else
        result = (long)b * bc + (long)w * wc;
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int b, w;
        cin >> b >> w;
        int bc, wc, z;
        cin >> bc >> wc >> z;
        long result = taumBday(b, w, bc, wc, z);
        cout << result << " ";
    }
    return 0;
}