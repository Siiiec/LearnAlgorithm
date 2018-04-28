#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

using ll = long long;

template <class T>
constexpr T nil = static_cast<T>(-1);

template <class T>
using vec = std::vector<T>;


void solve()
{
    using namespace std;
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<vector<ll>> dp(n, vector<ll>(n, nil<ll>));
    for (auto& x : v) cin >> x;

    ll count {};
    
    

    cout << count << endl;

}