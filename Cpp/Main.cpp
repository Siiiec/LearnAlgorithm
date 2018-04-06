#include <iostream>
#include <queue>
#include <functional>
#include "AOJ\ALDS1\12_GraphII\A_MinimumSpannningTree.hpp"


int main()
{
    using namespace std;
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