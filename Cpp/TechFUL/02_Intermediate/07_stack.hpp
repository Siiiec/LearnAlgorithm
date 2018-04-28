#include <iostream>
#include <array>
#include <string>

std::array<int, 101> stack;
int n = 0;

void push(int x)
{
    stack[n++] = x;
}

int pop()
{
    if (n > 0)
        return --n;
    else
        return 0;
}

void solve()
{
    using namespace std;
    int N;
    cin >> N;
    
    string str;
    int x;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> str >> x;
        if (str == "push")
            push(x);
        else
            pop();
    }

    for (int i = n - 1; i >= 0; --i)
    {
        cout << "stack[" << i << "] = " << stack[i] << endl;
    }
}