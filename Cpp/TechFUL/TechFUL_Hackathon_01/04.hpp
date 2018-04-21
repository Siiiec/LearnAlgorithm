#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve()
{
    using namespace std;
    int n, m;
    cin >> n >> m;

    vector<int> left(n);
    vector<int>right(m);

    for (auto& x : left)
        cin >> x;
    for (auto& x : right) 
        cin >> x;

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int lw = accumulate(left.cbegin(), left.cend(), 0);
    int rw = accumulate(right.cbegin(), right.cend(), 0);
    
    bool balanced = false;
    int lswap, rswap;

    for (auto l : left)
        for (auto r : right)
        {
            if (lw - l + r == rw - r + l)
            {
                balanced = true;
                lswap = l;
                rswap = r;
                goto LOOP_END;
            }
        }

LOOP_END:

    if (balanced)
        cout << lswap << '\n' << rswap << endl;
    else
        cout << "Error!" << endl;

}