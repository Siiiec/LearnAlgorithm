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

    int N;
    cin >> N;

    vec<int> v;
    v.push_back(1);

    for (int i = 6; i <= N; i *= 6)
    {
        v.push_back(i);
    }

    for (int i = 9; i <= N; i *= 9)
    {
        v.push_back(i);
    }

    sort(v.begin(), v.end());

    vec<vec<int>> dp(v.size() + 1, vec<int>(N + 1, 10000000));

    for (int i = 0; i < dp.size(); ++i)
        dp[i][0] = 0;

    for (int j = 0; j <= N; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= v.size(); ++i)
        for (int j = 0; j <= N; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);


            for (int k = 0; k < i; ++k)
                if (j >= v[k])
                    dp[i][j] = min({dp[i][j], dp[i - 1][j - v[k]] + 1, dp[i][j - v[k]] + 1});
        }

    cout << dp[v.size()][N] << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}