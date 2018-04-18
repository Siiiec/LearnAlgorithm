#include <iostream>
#include <string>

void solve()
{
    using namespace std;
    int yen, number;
    cin >> yen >> number;
    string str;
    if (yen <= 0 || number <= 0)
        str = "入力値エラーです。";
    else
        str = to_string(yen) + "円の商品を"
        + to_string(number) + "個買いました。\n合計金額は"
        + to_string(yen * number) + "円です。";

    cout << str << endl;
}