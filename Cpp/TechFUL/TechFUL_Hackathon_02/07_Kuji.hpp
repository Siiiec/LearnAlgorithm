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

    int w, h;
    cin >> w >> h;

    vec<string> kuji(h);

    for (auto& x : kuji)
    {
        string in;
        cin >> in;
        x = "0" + in + "0";
    }

    int currentW, in;
    cin >> in;

    currentW = 2 * (in - 1) + 1;

    for (int y = 0; y < kuji.size(); ++y)
    {
        if (kuji[y][currentW + 1] == '2')
            currentW += 2;
        else if (kuji[y][currentW - 1] == '2')
            currentW -= 2;
    }

    cout << (currentW + 1) / 2 << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}