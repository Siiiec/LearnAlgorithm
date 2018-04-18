#include <iostream>

void solve()
{
    using namespace std;
    int month;
    cin >> month;
    if (month >= 1 && month <= 12)
    {
        if (month >= 3 && month <= 5)
            cout << "t‚Å‚·B" << endl;
        else if (month >= 6 && month <= 8)
            cout << "‰Ä‚Å‚·B" << endl;
        else if (month >= 9 && month <= 11)
            cout << "H‚Å‚·B" << endl;
        else
            cout << "“~‚Å‚·B" << endl;
    }
    else
        cout << "‚»‚ñ‚ÈŒŽ‚Í‚ ‚è‚Ü‚¹‚ñ‚æB" << endl;
}