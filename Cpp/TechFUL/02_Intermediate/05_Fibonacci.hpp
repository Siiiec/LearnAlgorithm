#include <iostream>
#include <array>

using ll = long long;

constexpr int nil = -1;

std::array<ll, 45> ar;

ll fibo(ll n)
{
    if (ar[n] != nil)
        return ar[n];
    else
    {
        ar[n] = fibo(n - 1) + fibo(n - 2);
        return ar[n];
    }
}

void solve()
{
    using namespace std;
    for (auto& x : ar)
        x = nil;
    ar[0] = 1;
    ar[1] = 2;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << fibo(i) << (i + 1 != n ? ' ' : '\n');
    }
}