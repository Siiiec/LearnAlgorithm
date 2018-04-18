#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using ll = long long;

void solve()
{
    using namespace std;
    string s;
    getline(cin, s);

    vector<ll> count(26, 0);

    auto hasInvalidValue = any_of(s.cbegin(), s.cend(),
        [&count](int c)
    {
        if (isalpha(c))
        {
            ++count[c - (islower(c) ? 'a' : 'A')];
            return false;
        }
        else
            return true;
    });

    if (hasInvalidValue)
        cout << "“ü—Í’lƒGƒ‰[‚Å‚·" << endl;
    else
    {
        for (int i = 0; i < count.size(); ++i)
        {
            if (count[i] != 0)
                cout << static_cast<char>('a' + i) 
                << "=" << count[i] << "ŒÂ" << endl;
        }
    }
}