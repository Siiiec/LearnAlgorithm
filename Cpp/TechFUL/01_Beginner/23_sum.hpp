#include <iostream>
#include <vector>
#include <numeric>

int Normalize(int t)
{
    if (t > 100)
        return 99;
    else if (t < -100)
        return -99;
    else
        return t;
}

void solve()
{
    using namespace std;
    vector<int> v(5);
    for (int i = 0; i < v.size(); ++i)
    {
        cin >> v[i];
        v[i] = Normalize(v[i]);
    }

    cout << accumulate(v.cbegin(), v.cend(), 0) << endl;
}