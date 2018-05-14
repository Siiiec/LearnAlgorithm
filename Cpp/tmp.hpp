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

//ŠeŽínil
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

void solve()
{
    using namespace std;
    int n, l;
    cin >> n >> l;
    vector<string> v(n);
    for (auto& s : v) cin >> s;

    sort<>(v.begin(), v.end(), 
        [](string lhs, string rhs)
    {
        return lhs.compare(rhs) < 0;
    });

    for (auto s : v)
        cout << s;
    cout << endl;

}

//int main()
//{
//    solve();
//    return 0;
//}