#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int Access(const std::vector<int>& v, int i)
{
    if (i >= v.size())
        return 0;
    else
        return v[i];
}

int Bonus(const std::vector<int>& v, int i, bool strike)
{
    if (strike)
        return Access(v, i + 1) + Access(v, i + 2);
    else
        return Access(v, i + 1);
}

void solve()
{
    using namespace std;
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& x : v) cin >> x;
    int point {};

    for (int i = 0, f = 1; i < n; ++i, ++f)
    {
        if (Access(v, i) == 10)
        {
            point += 10 + (f < 10 ? Bonus(v, i, true) : 0);
        }
        else if (Access(v, i) + Access(v, i + 1) == 10)
        {
            point += 10 + (f < 10 ? Bonus(v, i + 1, false) : 0);
            ++i;
        }
        else
        {
            point += Access(v, i) + Access(v, i + 1);
            ++i;
        }
    }

    cout << point << endl;

}