#include <iostream>

void solve()
{
    using namespace std;
    int month;
    cin >> month;
    if (month >= 1 && month <= 12)
    {
        if (month >= 3 && month <= 5)
            cout << "�t�ł��B" << endl;
        else if (month >= 6 && month <= 8)
            cout << "�Ăł��B" << endl;
        else if (month >= 9 && month <= 11)
            cout << "�H�ł��B" << endl;
        else
            cout << "�~�ł��B" << endl;
    }
    else
        cout << "����Ȍ��͂���܂����B" << endl;
}