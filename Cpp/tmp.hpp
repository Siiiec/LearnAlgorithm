#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
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

//namespace std
//{
//    template<>
//    class hash<Key>
//    {
//    public:
//        size_t operator() (const Key& key) const
//        {
//            size_t seed = 0;
//            auto i_hash = hash<int>()(key.i_th);
//            auto w_hash = hash<int>()(key.W);
//
//            seed ^= i_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//            seed ^= w_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//
//            return seed;
//        }
//    };
//}

void solve()
{
    using namespace std;
    
    //int N;
    //cin >> N;

    //vec<int> p(N);
    //for (auto& x : p)
    //    cin >> x;

    //// dp[i + 1][j] i番目まででj点を作ることができる個数
    //vec<vec<int>> dp(p.size() + 1,vec<int>( N + 1, 0));
    //for (int i = 0; i <= p.size(); ++i)
    //    dp[i][0] = 1;

    //for (int i = 0; i < p.size(); ++i)
    //{

    //}

    //vec<bool> dp(10000 + 1, false);
    //dp[0] = true;

    //int maximum = accumulate(p.cbegin(), p.cend(), 0);

    //for (int i = 1; i <= maximum; ++i)
    //{
    //    for (int j = 0; j < p.size(); ++j)
    //        if (i >= p[j])
    //            dp[i] = dp[i] | dp[i - p[j]];
    //}

    //cout << count(dp.cbegin(), dp.cend(), true) << endl;

}

//int main()
//{
//    solve();
//    return 0;
//}