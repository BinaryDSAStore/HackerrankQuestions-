#include <bits/stdc++.h>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    int ans = 0;
    vector<int> count(8);

    //upward
    count[0] = n - r_q;
    //downward
    count[1] = r_q - 1;
    //right
    count[2] = n - c_q;
    //left
    count[3] = c_q - 1;
    //up-right
    count[4] = min(n - r_q, n - c_q);
    //up-left
    count[5] = min(n - r_q, c_q - 1);
    //down-right
    count[6] = min(r_q - 1, n - c_q);
    //down-left
    count[7] = min(r_q - 1, c_q - 1);

    for(int i{0}; i<obstacles.size(); i++)
    {
        if(obstacles[i][0] == r_q)
        {
            if(obstacles[i][1] > c_q)
                count[2] = min(count[2], obstacles[i][1] - c_q - 1);
            else
                count[3] = min(count[3], c_q - obstacles[i][1] - 1);
        }
        else if(obstacles[i][1] == c_q)
        {
            if(obstacles[i][0] > r_q)
                count[0] = min(count[0], obstacles[i][0] - r_q - 1);
            else
                count[1] = min(count[1], r_q - obstacles[i][0] - 1);
        }
        else if(abs(obstacles[i][0] - r_q) == abs(obstacles[i][1] - c_q))
        {
            if(obstacles[i][0] > r_q && obstacles[i][1] > c_q)
                count[4] = min(count[4], obstacles[i][0] - r_q - 1);
            else if(obstacles[i][0] > r_q && obstacles[i][1] < c_q)
                count[5] = min(count[5], obstacles[i][0] - r_q - 1);
            else if(obstacles[i][0] < r_q && obstacles[i][1] > c_q)
                count[6] = min(count[6], r_q - obstacles[i][0] - 1);
            else
                count[7] = min(count[7], r_q - obstacles[i][0] - 1);
        }
    }

    for(int i{0}; i<8; i++)
        ans += count[i];
    
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;
    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++)
    {
        obstacles[i].resize(2);
        for (int j = 0; j < 2; j++)
            cin >> obstacles[i][j];
    }
    int result = queensAttack(n, k, r_q, c_q, obstacles);
    cout << result << endl;
    return 0;
}