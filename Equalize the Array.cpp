#include <bits/stdc++.h>
using namespace std;

int equalizeArray(vector<int> arr)
{
    int max = 0;
    unordered_map<int, int> m;
    for (int i : arr)
    {
        m[i]++;
        if (m[i] > max)
            max = m[i];
    }
    return arr.size() - max;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << equalizeArray(arr) << endl;
    return 0;
}