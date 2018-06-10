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

struct Item
{
    int value;
    int weight;
};

struct Key
{
    int i_th;
    int W;

    bool operator==(const Key& rhs) const
    {
        return i_th == rhs.i_th && W == rhs.W;
    }

    bool operator!=(const Key& rhs) const
    {
        return *this == rhs;
    }
};

namespace std
{
    template<>
    class hash<Key>
    {
    public:
        size_t operator() (const Key& key) const
        {
            size_t seed = 0;
            auto i_hash = hash<int>()(key.i_th);
            auto w_hash = hash<int>()(key.W);

            seed ^= i_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= w_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);

            return seed;
        }
    };
}


class DpKnapsack
{
private:
    static constexpr ll nil = -1;

    vec<Item> items;
    //vec<vec<ll>> dp;
    std::unordered_map<Key, ll> dp;
    ll W;

public:
    DpKnapsack(vec<Item> items, ll W)
        : items {items}
        //, dp {vec<vec<ll>>(items.size(), vec<ll>(W + 1, nil))}
        , W {W}
    {}

    ll ans(int w)
    {
        return solve(items.size() - 1, w);
    }

private:

    // i番目の品物までで制約jのときの最大値
    ll solve(int i, int j)
    {
        if (i < 0 || j <= 0)
            return 0;

        Key current {i, j};

        if (dp.count(current) != 0)
            return dp.at(current);

        //dp.emplace(current);
        auto& currentDp = dp[current];

        currentDp = solve(i - 1, j);
        if (j >= items[i].weight)
            currentDp = std::max(currentDp, solve(i - 1, j - items[i].weight) + items[i].value);

        return currentDp;
    }

};

void solve()
{
    using namespace std;

    // Wが小さいときのナップサック
    int N, W;
    cin >> N >> W;
    vec<Item> items(N);
    for (auto & x : items)
        cin >> x.weight >> x.value;

    DpKnapsack dp {items, W};

    cout << dp.ans(W) << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}