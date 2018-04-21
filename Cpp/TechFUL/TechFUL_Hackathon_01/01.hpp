#include <iostream>

void solve()
{
    using namespace std;
    int n1, n2;
    cin >> n1 >> n2;

    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
            cout << '*';
        cout << endl;
    }

    cout << (n1 == n2 ? "square" : "rectangle") << endl;

}