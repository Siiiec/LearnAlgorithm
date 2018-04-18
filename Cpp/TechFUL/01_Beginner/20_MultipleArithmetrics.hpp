#include <iostream>

void solve()
{
    using namespace std;
    int a, b;
    cin >> a >> b;

    if (a == 0 || b == 0)
    {
        cout << "入力値エラーです。" << endl;
    }
    else
    {
        cout << "a=" << a << endl;
        cout << "b=" << b << endl;
        cout << "a%b=" << a % b << endl;
        cout << "b-a=" << b - a << endl;
        cout << "b/a=" << b / a << endl;
        cout << "b%a=" << b % a << endl;
    }


}