#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> sosuu(int n)
{
    using namespace std;
    vector<bool> b(n + 1, true);
    b[0] = b[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (!b[i])
            continue;

        for (int j = i * 2; j <= n; j += i)
            b[j] = false;
    }
    
    return b;
}

void solve()
{
    using namespace std;
    int n;
    cin >> n;
    auto b = sosuu(n);
    
    cout << 2 << "‚©‚ç" << b.size() - 1 << "‚Ü‚Å‚Ì‘f”" << endl;
    for (int i = 2; i < b.size(); ++i)
    {
        if (b[i])
        {
            cout << i;
            if (i + 1 != n)
                cout << ' ';
        }
    }
    cout << endl;
}