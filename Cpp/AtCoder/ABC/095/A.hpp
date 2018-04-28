#include <iostream>
#include <vector>
#include <string>
#include <numeric>

void solve()
{
    using namespace std;
    string s;
    cin >> s;

    int price = accumulate(s.cbegin(), s.cend(), 700,
        [](int init, char c)
    { 
        return init + (c == 'o' ? 100 : 0);
    });

    cout << price << endl;

}