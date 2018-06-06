#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
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
    ll X;
    cin >> X;
    double n = ceil(0.5 * (-1 + sqrt(1 + 8 * X)));
    cout << (ll)(n) << endl;

}

//int main()
//{
//    solve();
//    return 0;
//}