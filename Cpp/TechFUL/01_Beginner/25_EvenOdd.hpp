#include <iostream>

void solve()
{
    using namespace std;
    int no, cont;

    while (true)
    {
        cin >> no;
        if (no % 2 == 0)
            cout << "その数は偶数です。" << endl;
        else
            cout << "その数は奇数です。" << endl;

        cout << "続けますか。" << endl;
        cin >> cont;

        if (cont == 1)
            continue;
        else if (cont == 9)
        {
            cout << "終了します。" << endl;
            break;
        }
        else
        {
            cout << "入力値エラーです。" << endl;
            break;
        }

    }

}