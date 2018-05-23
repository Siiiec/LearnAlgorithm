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


    using bit = bitset<4>;

    int C;
    string s;
    cin >> C >> s;

    int lhs {};
    for (int i = 0; i < C; ++i)
        lhs += 9 * pow(10, i);

    for (int i = 0; i < C; ++i)
    {
        bit b(s.substr(i, i + 4));
    }

}

//int main()
//{
//    solve();
//    return 0;
//}