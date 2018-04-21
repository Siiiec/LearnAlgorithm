#include <iostream>

using ll = long long;

void solve()
{
    using namespace std;
    ll f, u, l;
    cin >> f >> u >> l;

    auto lap = (l + f) / u;
    auto currentInLap = l + f - (lap * u);

    if (lap % 2 == 0)
    {
        if (currentInLap > f)
            cout << u - currentInLap + u - f;
        else
            cout << f - currentInLap;
    }
    else
    {
        if (currentInLap > u - f)
            cout << currentInLap - (u - f) + f;
        else
            cout << u - f - currentInLap;
    }
}