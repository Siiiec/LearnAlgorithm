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

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int in;
        cin >> in;

        int N = in;

        while (true)
        {
            auto str = to_string(N);
            int sumOfDigit {};
            bool allNineOrZero = true;
            for (int j = 0; j < str.size(); ++j)
            {
                auto subs = str.substr(j, 1);
                sumOfDigit += stoi(subs);
                if (subs != "0" && subs != "9")
                    allNineOrZero = false;
            }

            if (allNineOrZero && sumOfDigit % 9 == 0)
            {
                cout << N << endl;
                break;
            }

            N += in;
        }
    }


}

//int main()
//{
//    solve();
//    return 0;
//}