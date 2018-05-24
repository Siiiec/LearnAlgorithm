#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <valarray>
#include <utility>
#include <tuple>
#include <cmath>
#include <random>

using ll = long long;

//vector
template <class T>
using vec = std::vector<T>;

struct Item
{
    int weight, value;
};

void solve()
{
    using namespace std;

    int c, r;
    cin >> c >> r;

    vector<string> figure(r);

    for (auto& x : figure)
        cin >> x;

    int order;
    cin >> order;

    if (order == 1)
    {
        reverse(figure.begin(), figure.end());
        for (auto& x : figure)
            cout << x << endl;
    }
    else if (order == 2)
    {
        for (auto& x : figure)
            reverse(x.begin(), x.end());
        for (auto& x : figure)
            cout << x << endl;

    }
    else
    {
        int deg;
        cin >> deg;
        deg = (deg / 90) % 4;
        if (order == 4)
            deg = (4 - deg) % 4;

        if (deg == 0)
            for (auto& x : figure)
                cout << x << endl;
        else if (deg == 1)
            for (int x = 0; x < figure[0].size(); ++x)
            {
                for (int y = figure.size() - 1; y >= 0; --y)
                    cout << figure[y][x];
                cout << endl;
            }
        else if (deg == 2)
            for (int y = figure.size() - 1; y >= 0; --y)
            {
                for (int x = figure[0].size() - 1; x >= 0; --x)
                    cout << figure[y][x];
                cout << endl;
            }
        else
            for (int x = figure[0].size() - 1; x >= 0; --x)
            {
                for (int y = 0; y < figure.size(); ++y)
                    cout << figure[y][x];
                cout << endl;
            }

    }


}

//int main()
//{
//    solve();
//    return 0;
//}