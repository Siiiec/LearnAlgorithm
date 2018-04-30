#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstdio>

void solve()
{
    using namespace std;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    double mean = floor(static_cast<double>(accumulate(v.cbegin(), v.cend(), 0)) * 10 / n) / 10;

    printf("%.1f", mean);
}