#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

void solve()
{
    using namespace std;
    string s;
    getline(cin, s);
    //cin >> s;

    vector<int> count(10, 0);

    for_each(s.cbegin(), s.cend(),
        [&count](char c)
    {
        if (isdigit(c))
            ++count[stoi(string {c})];
    });

    if (all_of(count.cbegin(), count.cend(), [](int x) { return x == 0; }))
    {
        cout << "���͒l�G���[�ł��B" << endl;
    }
    else
    {
        for (auto i = 0; i < count.size(); ++i)
        {
            cout << i << "=" << count[i] << "��" << endl;
        }
    }
}