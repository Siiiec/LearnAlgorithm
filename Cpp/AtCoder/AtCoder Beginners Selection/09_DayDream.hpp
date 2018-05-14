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
#include <cmath>

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


//
//Œã‚ë‚©‚ç’²‚×‚é
//

void solve()
{
    using namespace std;

    array<string, 4> daydream = {"dream", "dreamer", "erase", "eraser"};

    string str;
    cin >> str;

    reverse(str.begin(), str.end());
    for (auto& d : daydream) reverse(d.begin(), d.end());

    bool can = true;

    for (int i = 0; i < str.size();)
    {
        bool can2 = false;
        for (const auto& d : daydream)
            if (str.substr(i, d.size()) == d)
            {
                can2 = true;
                i += d.size();
            }

        if (!can2)
        {
            can = false;
            break;
        }
    }

    cout << (can ? "YES" : "NO") << endl;

}

//int main()
//{
//    solve();
//    return 0;
//}
