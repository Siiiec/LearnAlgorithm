#include <iostream>

void solve()
{
    using namespace std;
    int no, cont;

    while (true)
    {
        cin >> no;
        if (no % 2 == 0)
            cout << "���̐��͋����ł��B" << endl;
        else
            cout << "���̐��͊�ł��B" << endl;

        cout << "�����܂����B" << endl;
        cin >> cont;

        if (cont == 1)
            continue;
        else if (cont == 9)
        {
            cout << "�I�����܂��B" << endl;
            break;
        }
        else
        {
            cout << "���͒l�G���[�ł��B" << endl;
            break;
        }

    }

}