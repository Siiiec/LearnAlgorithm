#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void solve()
{
    using namespace std;
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    x -= accumulate(v.cbegin(), v.cend(), 0);
    int min = accumulate(v.cbegin(), v.cend(), v[0],
        [](int init, int x)
    {
        if (init > x)   return x;
        else            return init;
    });

    cout << n + x / min << endl;

}