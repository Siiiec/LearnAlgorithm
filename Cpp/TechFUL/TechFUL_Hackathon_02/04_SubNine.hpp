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

    using bit = bitset<4>;

    ll C;
    string str;
    cin >> C;
    cin >> str;

    ll num = pow(10, C) - 1;

    ll subNum {};

    for (int i = 0; i < C; ++i)
    {
        auto digit = bit(str.substr(i * 4, 4)).to_ulong() - 3;
        subNum += digit * pow(10, C - i - 1);
    }


    auto ans = to_string(num - subNum);

    while (ans.size() < C)
        ans = "0" + ans;

    for (int i = 0; i < ans.size(); ++i)
    {
        auto c = bit(stoi(ans.substr(i, 1)) + 3).to_string();
        cout << c;
    }


}

//int main()
//{
//    solve();
//    return 0;
//}