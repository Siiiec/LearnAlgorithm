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

//äeéÌnil
template <class T>
constexpr T nil = static_cast<T>(-1);

constexpr int nil_i = nil<int>;
constexpr int nil_ll = nil<ll>;
constexpr double nil_d = nil<double>;

//vector
template <class T>
using vec = std::vector<T>;

void solve()
{
    using namespace std;

    constexpr int inf = 1 << 29;

    int n, m;   //n:ï•Ç§ã‡äz, m:ÉRÉCÉìÇÃéÌóﬁ
    cin >> n >> m;
    vec<int> c(m);
    for (auto& x : c) cin >> x;

    vec<int> dp(n + 1, inf);    //mâ~ï•Ç§Ç∆Ç´ÇÃç≈è¨ñáêî

    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < m; ++j)
            if (i >= c[j])
                dp[i] = min(dp[i], dp[i - c[j]] + 1);

    cout << dp[n] << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}