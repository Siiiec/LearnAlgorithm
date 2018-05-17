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

void solve()
{
    using namespace std;
    ll N, M;
    cin >> N >> M;

    vec<int> P(N);

    for (auto& p : P) cin >> p;

    ll maxPoint {};

    sort(P.begin(), P.end());

    //4重ループの場合 1000^4=10^12
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                for (int l = 0; l < N; ++l)
                {
                    ll sum = P[i] + P[j] + P[k] + P[l];
                    if (sum <= M)
                    {
                        maxPoint = max(maxPoint, sum);
                    } 
                }

    //3重ループ 1000^3=10^9
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
            {
                
            }

    cout << maxPoint << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}