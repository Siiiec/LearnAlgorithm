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
    
    constexpr int maxK = 5000;
    
    int N, K;
    cin >> N >> K;

    vec<int> a(N);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    //dp[j + 1][j]jî‘ñ⁄Ç‹Ç≈Ç≈íljÇçÏÇÍÇÈÇ©Ç«Ç§Ç©
    vec<vec<int>> dp(N + 1, vec<int>(maxK + 1, 100000));

    for (int i = 0; i <= N; ++i)
        dp[i][0] = 0;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= maxK; ++j)
        {
            dp[i + 1][j] = dp[i][j];
            if (j >= a[i])
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - a[i]] + 1);
        }
    
    vec<int> v;

    for (int j = 0; j < dp[N].size(); ++j)
        if (dp[N][j] != 100000)
            v.push_back(j);

    int count {};
    for (int i = 0; i < N; ++i)
    {
        bool important = any_of(v.cbegin(), v.cend(), 
            [K, &a, i](int x)
        {
            return x >= K && x < K + a[i];
        });

        if (!important)
            ++count;
    }

    cout << count << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}