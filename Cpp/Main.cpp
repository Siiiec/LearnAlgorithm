#include <iostream>
#include <queue>
#include <functional>
#include "AOJ\ALDS1\11_GraphI\D_ConnectedComponents.hpp"

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> qu;
    
    for (int i = 0; i < 10; ++i)
        qu.push(i);

    for (int i = 0; i < 10; ++i)
    {
        cout << qu.top();
        qu.pop();
    }

    //solve();
    return 0;
}