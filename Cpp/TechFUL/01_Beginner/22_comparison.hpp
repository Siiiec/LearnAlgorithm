#include <iostream>
#include <utility>

bool InRange(int t)
{
    return (t > 9 && t < 100);
}

void solve()
{
    using namespace std;

    int num1, num2;
    cin >> num1 >> num2;

    if (num1 == num2)
    {
        cout << "�����l�ł�" << endl;
    }
    else if (InRange(num1) && InRange(num2))
    {
        if (num1 > num2)
        {
            cout << "num1:" << num1 << endl;
        }
        else if (num1 < num2)
        {
            cout << "num2:" << num2 << endl;
        }
    }
    else
    {
        cout << "�s���ȓ��͒l�ł�" << endl;
    }
}