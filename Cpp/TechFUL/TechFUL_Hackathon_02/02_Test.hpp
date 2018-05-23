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

    int n; cin >> n;

    vector<int> p(n - 1);
    for (auto& x : p) cin >> x;

    double pa;
    cin >> pa;

    int sum = accumulate(p.cbegin(), p.cend(), 0);

    double allSum = pa * n;

    int point = static_cast<int>(allSum - sum);

    cout << point << endl;

}

//int main()
//{
//    solve();
//    return 0;
//}