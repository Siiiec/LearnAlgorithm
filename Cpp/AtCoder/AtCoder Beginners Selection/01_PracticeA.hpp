#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <set>
#include <utility>

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

void solve()
{
    using namespace std;
    int a, b, c;
    string s;
    
    cin >> a >> b >> c >> s;

    cout << a + b + c << " " << s << endl;
}