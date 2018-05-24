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

    string pat, str;
    cin >> pat >> str;

    int aNum {}, bNum {};

    int firstA {100000}, firstB {100000};

    for (int i = 0; i < pat.size(); ++i)
        if (pat[i] == 'A')
        {
            firstA = min(firstA, i);
            ++aNum;
        }
        else
        {
            firstB = min(firstB, i);
            ++bNum;
        }

    string A, B;

    for (int aLength = 1; aLength < str.size(); ++aLength)
    {
        int bLength = (str.size() - aNum * aLength) / bNum;
        if (bLength < 0)
            continue;

        if (pat[0] == 'A')
        {
            A = str.substr(0, aLength);
            B = str.substr(firstB * aLength, bLength);
        }
        else
        {
            B = str.substr(0, bLength);
            A = str.substr(firstA * bLength, aLength);
        }

        string cons;
        for (auto c : pat)
            if (c == 'A')
                cons.append(A);
            else
                cons.append(B);

        if (cons == str)
            break;
    }

    cout << "A=" << A << endl;
    cout << "B=" << B << endl;

}

//int main()
//{
//    solve();
//    return 0;
//}