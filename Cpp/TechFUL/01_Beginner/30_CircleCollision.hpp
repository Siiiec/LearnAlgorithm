#include <iostream>
#include <algorithm>
#include <cmath>

bool InRangeC(int t)
{
    return t >= -256 && t <= 255;
}

bool InRangeR(int t)
{
    return t >= 1 && t <= 50;
}

bool Intersect(int cx1, int cy1, int r1, int cx2, int cy2, int r2)
{
    return pow(cx1 - cx2, 2) + pow(cy1 - cy2, 2) < pow(r1 + r2, 2);
}

void solve()
{
    using namespace std;
    int cx1, cy1, r1, cx2, cy2, r2;
    cin >> cx1 >> cy1 >> r1 >> cx2 >> cy2 >> r2;
    auto c = {cx1, cy1, cx2, cy2};
    auto r = {r1, r2};

    if (all_of(c.begin(), c.end(), [](int x) { return InRangeC(x); })
        && all_of(r.begin(), r.end(), [](int x) { return InRangeR(x); }))
    {
        cout << (Intersect(cx1, cy1, r1, cx2, cy2, r2) ? "hit" : "not") << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

}