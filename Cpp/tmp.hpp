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

void solve()
{
    using namespace std;
    int n;
    cin >> n;

    constexpr int female = 0;
    constexpr int male = 1;

    constexpr int notMatched = -1;
    constexpr int matched = 10;

    vec<vec<int>> match(2, vec<int>(n, notMatched));

    vec<vec<int>> frank(n);
    vec<vec<int>> mrank(n);
    vec<int> ans(n);

    //“ü—Í(—«)
    for (auto& v : frank)
    {
        for (int i = 0; i < n; ++i)
        {
            int in;
            cin >> in;
            v.push_back(in - 1);
        }
    }
    //“ü—Í(’j«)
    for (auto& v : mrank)
    {
        for (int i = 0; i < n; ++i)
        {
            int in;
            cin >> in;
            v.push_back(in - 1);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        set<string> se;
        //FtoM
        for (int f = 0; f < n; ++f)
        {
            if (match[female][f] == matched)
                continue;
            for (int j = 0; j < n; ++j)
            {
                int m = frank[f][j];
                if (match[male][m] != matched)
                {
                    se.emplace(to_string(f) + to_string(m));
                    break;
                }
            }
        }

        //MtoF
        for (int m = 0; m < n; ++m)
        {
            if (match[male][m] == matched)
                continue;
            for (int j = 0; j < n; ++j)
            {
                int f = mrank[m][j];
                if (match[female][f] != matched)
                {
                    auto matchStr = to_string(f) + to_string(m);
                    if (se.count(matchStr) != 0)
                    {
                        match[male][m] = matched;
                        match[female][f] = matched;
                        ans[f] = m + 1;
                        break;
                    }

                }
            }
        }

    }



    for (auto m : ans)
        cout << m << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}