#include <iostream>

void solve()
{
    using namespace std;
    int month;
    cin >> month;
    if (month >= 1 && month <= 12)
    {
        if (month >= 3 && month <= 5)
            cout << "春です。" << endl;
        else if (month >= 6 && month <= 8)
            cout << "夏です。" << endl;
        else if (month >= 9 && month <= 11)
            cout << "秋です。" << endl;
        else
            cout << "冬です。" << endl;
    }
    else
        cout << "そんな月はありませんよ。" << endl;
}