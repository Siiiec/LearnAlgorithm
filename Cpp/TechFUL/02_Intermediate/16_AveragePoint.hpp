#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iomanip>
#include <vector>
#include <cmath>

using ll = long long;

template <class T>
using vec = std::vector<T>;

template <class T>
constexpr T nil = static_cast<T>(-1);

template <class T>
constexpr T inf = std::numeric_limits<T>::max() / 2;


void solve()
{
    using namespace std;

    vector<int> v;

    bool ranged = true;

    for (int i = 0, in; i < 3; ++i)
    {
        cin >> in;
        if (in >= 0 && in <= 100)
            v.push_back(in);
        else if (in == -1)
            continue;
        else
        {
            cout << "”ÍˆÍŠO‚Ì“¾“_‚ª‚ ‚è‚Ü‚·" << endl;
            return;
        }
    }

    double mean = accumulate(v.cbegin(), v.cend(), 0.0);
    
    if (v.size() != 0)
        mean /= v.size();

    mean = floor(mean * 100.0) / 100.0;

    cout << fixed << setprecision(2) << mean << endl;
}