#include <iostream>
#include <vector>
#include <utility>

void solve()
{
    using namespace std;
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = v.size() - 1; j > i; --j)
        {
            if (v[j] > v[j - 1])
                swap(v[j], v[j - 1]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << v[i];
        cout << (i + 1 != n ? ' ' : '\n');
    }
}