#include <iostream>
#include <string>

void solve()
{
    using namespace std;
    int yen, number;
    cin >> yen >> number;
    string str;
    if (yen <= 0 || number <= 0)
        str = "���͒l�G���[�ł��B";
    else
        str = to_string(yen) + "�~�̏��i��"
        + to_string(number) + "�����܂����B\n���v���z��"
        + to_string(yen * number) + "�~�ł��B";

    cout << str << endl;
}