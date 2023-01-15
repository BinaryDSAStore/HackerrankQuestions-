#include <bits/stdc++.h>
using namespace std;

class Queue2Stacks
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    void dequeue()
    {
        if (s1.empty() && s2.empty())
            return;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int front()
    {
        if (s1.empty() && s2.empty())
            return -1;

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};

int main()
{
    int t{0};
    Queue2Stacks list;

    cin >> t;
    while (t--)
    {
        int type{0};
        cin >> type;
        if (type == 1)
        {
            int val{0};
            cin >> val;
            list.enqueue(val);
        }
        else if (type == 2)
        {
            list.dequeue();
        }
        else
        {
            cout << list.front() << endl;
        }
    }
}