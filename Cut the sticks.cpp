#include <bits/stdc++.h>
using namespace std;

vector<int> cutTheSticks(vector<int> arr)
{
    vector<int> ans;
    while (arr.size() > 0)
    {
        ans.push_back(arr.size());
        int min = *min_element(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] -= min;
            if (arr[i] == 0)
            {
                arr.erase(arr.begin() + i);
                i--;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> result = cutTheSticks(arr);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    cout << endl;
    return 0;
}