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

void Q03_PartialSumBool()
{
    using namespace std;

    int n, A;
    cin >> n >> A;
    vec<int> v(n);
    for (auto& x : v) cin >> x;

    //dp[i+1][j] : i�Ԗڂ܂łŒlj�����邩
    vec<vec<bool>> dp(n+1, vec<bool>(A + 1, false));

    //�����l�̐ݒ�
    dp[0][0] = true;

    //���炤DP
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= A; ++j)
        {
            //
            dp[i + 1][j] = dp[i + 1][j] | dp[i][j];
            if (v[i] <= j)
                dp[i + 1][j] = dp[i+1][j] | dp[i][j-v[i]];
        }
    
    if (dp[n][A]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void Q04_PartialSumCount()
{
    using namespace std;

    constexpr int MOD = 1000000009;

    int n, A;
    cin >> n >> A;
    vec<int> v(n);
    for (auto& x : v) cin >> x;

    //dp[i+1][j] : i�Ԗڂ܂łŒlj�������邩
    vec<vec<int>> dp(n + 1, vec<int>(A + 1, 0));

    //�����l
    //�v�f��0��0������
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= A; ++j)
        {
            (dp[i + 1][j] += dp[i][j]) %= MOD;
            //�I�ׂ�Ƃ�
            if (j >= v[i]) (dp[i + 1][j] += dp[i][j - v[i]]) %= MOD;
        }

    cout << dp[n][A] << endl;
}

void Q05_MinimalPartialSumCount()
{
    using namespace std;

    //�I�[�o�[�t���[�h�~�̂��߁A��������������
    constexpr int inf = 1 << 29;

    int n, A;
    cin >> n >> A;

    vec<int> a(n);
    for (auto& x : a) cin >> x;

    //dp[i+1][j]    i�Ԗڂ̗v�f�܂ł�j������ŏ���
    //���Ȃ��ꍇ��-1
    vec<vec<int>> dp(n + 1, vec<int>(A + 1, inf));

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= A; ++j)
        {
            dp[i + 1][j] = min(dp[i + 1][j] ,dp[i][j]);
            if (j >= a[i])
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - a[i]] + 1);
        }

    if (dp[n][A] < inf) cout << dp[n][A] << endl;
    else cout << -1 << endl;
}

void solve()
{
    Q05_MinimalPartialSumCount();
}

//int main()
//{
//    solve();
//    return 0;
//}