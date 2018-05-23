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

void solve()
{
    using namespace std;

    int n, m, f, u;
    cin >> n >> m >> f >> u;

    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            if (i * f + j * u == n && i + j == m)
            {
                cout << i << endl << j << endl;
                break;
            }
}

//int main()
//{
//    solve();
//    return 0;
//}