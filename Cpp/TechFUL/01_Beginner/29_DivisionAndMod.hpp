#include <iostream>

void solve()
{
    using namespace std;
    int n1, n2;
    cin >> n1 >> n2;

    if (n1 >= 0 && n1 <= 255 && n2 >= 1 && n2 <= 55)
    {
        cout << n1 / n2;
        if (n1 % n2 != 0)
            cout << "..." << n1 % n2;

        cout << endl;
    }
    else    //�͈͊O
    {
        cout << "Error" << endl;
    }
}