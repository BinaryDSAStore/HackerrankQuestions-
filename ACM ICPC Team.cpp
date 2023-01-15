#include <bits/stdc++.h>
using namespace std;

vector<int> acmTeam(vector<string> topic)
{
    int n = topic.size();
    int m = topic[0].size();
    int max = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < m; k++)
                if (topic[i][k] == '1' || topic[j][k] == '1')
                    sum++;
            if (sum > max)
            {
                max = sum;
                count = 1;
            }
            else if (sum == max)
                count++;
        }
    }
    vector<int> result;
    result.push_back(max);
    result.push_back(count);
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> topic(n);
    for (int i = 0; i < n; i++)
    {
        cin >> topic[i];
    }
    vector<int> result = acmTeam(topic);
    for (ssize_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}