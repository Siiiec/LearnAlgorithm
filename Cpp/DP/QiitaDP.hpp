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

//�e��nil
template <class T>
constexpr T nil = static_cast<T>(-1);

constexpr int nil_i = nil<int>;
constexpr int nil_ll = nil<ll>;
constexpr double nil_d = nil<double>;

//vector
template <class T>
using vec = std::vector<T>;

template <class T>
struct Vec2D
{
    T x, y;
};

//https://qiita.com/drken/items/a5e6fe22863b7992efdb

void Q01_MaximumSum()
{
    //n�̐��� a[0], a[1], ..., a[n-1]���^������B�����̐������牽���̐�����I��ő��a���Ƃ����Ƃ��́A���a�̍ő�l�����߂�B�܂��A�����I�΂Ȃ��ꍇ�̑��a�� 0 �ł�����̂Ƃ���B

    using namespace std;
    int n; cin >> n;

    vec<int> v(n), dp(n);
    for (auto& x : v) cin >> x;

    dp[0] = max(v[0], 0);

    for (int i = 1; i < n; ++i)
        dp[i] = max(dp[i - 1], dp[i - 1] + v[i]);

    cout << dp[n - 1] << endl;
}

struct Item
{
    int value;
    int weight;
};

void Q02_Knapsack()
{
    //AOJ DPL_1_B

    using namespace std;

    int n, W; cin >> n >> W;


    vec<Item> items(n);
    for (auto& x : items) cin >> x.value >> x.weight;

    //dp[i+1][W] : i�Ԗڂ̕i���܂łŁA�d����W�𒴂��Ȃ��悤�ɂ����Ƃ��̉��l�̍ő�l
    vec<vec<int>> dp(n + 1, vec<int>(W + 1, 0));

    for (int i = 0; i < n; ++i)
        for (int w = 1; w <= W; ++w)
        {
            if (items[i].weight <= w)
                dp[i + 1][w] = max(dp[i][w], dp[i][w - items[i].weight] + items[i].value);
            else
                dp[i + 1][w] = dp[i][w];
        }

    cout << dp[n][W] << endl;
}

void Q03_PartialSum()
{
    using namespace std;

    int n, A;
    cin >> n >> A;
    vec<int> v(n);
    for (auto& x : v) cin >> x;

    //dp[i+1][j] : i�Ԗڂ܂łŒlj�����邩
    vec<vec<bool>> dp(n+1, vec<bool>(A, false));

    //�����l�̐ݒ�
    dp[0][0] = true;

    for (int i = 0; i < n; ++i)
        for (int j = 1; j < A; ++j)
        {
            dp[i + 1][j] = dp[i + 1][j] | dp[i][j];
            if (v[i] <= j && dp[i][j - v[i] == 0) dp[i + 1][j] = true;
        }


}

void solve()
{
    Q03_PartialSum();
}

//int main()
//{
//    solve();
//    return 0;
//}