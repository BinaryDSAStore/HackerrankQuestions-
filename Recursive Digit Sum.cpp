#include<bits/stdc++.h>
using namespace std;

long long func(string n)
{
    long long sum = 0;
    for (int i = 0; i < n.size(); i++)
        sum += n[i] - '0';
    return sum;
}

int superDigit(string n, int k)
{
    long long sum = func(n);
    sum *= k;
    while (sum > 9)
    {
        string s = to_string(sum);
        sum = func(s);
    }
    return sum;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;
    cout << superDigit(n, k) << endl;
    return 0;
}