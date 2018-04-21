#include <iostream>
#include <vector>

using ll = long long;

void solve()
{
    using namespace std;
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ab = a + b;
    int cc = c * 2;
    ll price = 0;

    while (x > 0 || y > 0)
    {
        if (cc < a && x > 0)
        {
            --x;
            --y;
            price += cc;
        }
        else if (cc < b && y > 0)
        {
            --x;
            --y;
            price += cc;
        }
        else if (cc < ab && x > 0 && y > 0)
        {
            --x;
            --y;
            price += cc;
        }
        else if (y > 0)
        {
            --y;
            price += b;
        }
        else if (x > 0)
        {
            --x;
            price += a;
        }
    }

    cout << price << endl;

}