#include <iostream>
#include <iomanip>
#include <string>

void solve()
{
    using namespace std;
    int n;
    cin >> n;

    cout << "   ";
    for (int i = 0; i < n; ++i)
    {
        cout << setw(2) << setfill('0') << i;
        if (i != n - 1)
            cout << ' ';
    }

    for (int c = ' ', i = 0; c != '~' + 1; ++c, ++i)
    {
        if (i % n == 0)
            cout << endl << setw(2) << setfill('0') << i / n + 2 
            << setfill(' ') << setw(1) << " ";
        else
            cout << ' ';

        cout << setw(2) << char_traits<char>::char_type(c);
    }
    cout << endl;
}