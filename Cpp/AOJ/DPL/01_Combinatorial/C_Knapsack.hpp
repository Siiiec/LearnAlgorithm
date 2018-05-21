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

//各種nil
template <class T>
constexpr T nil = static_cast<T>(-1);

constexpr int nil_i = nil<int>;
constexpr int nil_ll = nil<ll>;
constexpr double nil_d = nil<double>;

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

    constexpr int inf = 1 << 29;

    int N, W;
    cin >> N >> W;

    vec<Item> items(N);
    for (auto& i : items) cin >> i.value >> i.weight;

    //dp[w] 重さw以下のときの価値の最大値
    vec<vec<int>> dp(N + 1, vec<int>(W + 1, 0));

    for (int i = 0; i < N; ++i)
        for (int w = 0; w <= W; ++w)
        {
            if (items[i].weight <= w)
                dp[i + 1][w] = max(dp[i][w], dp[i + 1][w - items[i].weight] + items[i].value);
            else
                dp[i + 1][w] = dp[i][w];
        }

    cout << dp[N][W] << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}