#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <valarray>
#include <iomanip>
#include <algorithm>

void solve()
{
    using namespace std;

    constexpr int n = 8;

    string str = "ABCDEFGH";
    array<int, n> ar;
    ar[0] = 0;
    for (int i = 1; i < n; ++i) cin >> ar[i];

    int in, out;
    cin >> in >> out;

    array<int, n> dist;
    partial_sum(ar.cbegin(), ar.cend(), dist.begin());
    const auto cdist = dist;
    
    int d, f;

    array<array<int, n>, n> aa;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j) dist[j] -= ar[i];

        for (int j = 0; j < n; ++j)
        {
            if (j < i)
            {
                aa[i][j] = (cdist[i] - cdist[j]) * 20;
            }
            else
            {
                aa[i][j] = dist[j];
            }
        }
    }

    cout << " ";
    for (const auto& s : str) cout << setw(5) << s;
    cout << endl;

    for (int i = 0; i < n; ++i)
    {
        cout << str[i];
        for (int j = 0; j < n; ++j)
            cout << setw(5) << (in - out > 0 ? aa[i][j] : aa[j][i]);
        cout << endl;
    }



    if (in - out > 0)
    {
        cout << aa[out][in] << endl;
        cout << aa[in][out] << endl;
    }
    else
    {
        cout << aa[in][out] << endl;
        cout << aa[out][in] << endl;
    }


}