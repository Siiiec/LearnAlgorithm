#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

constexpr int divideByZero = -10000;

int Calc(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else
        return b != 0 ? a / b : divideByZero;
}

void solve()
{
    using namespace std;
    string s;
    cin >> s;
    auto opIter = find_if_not(s.cbegin(), s.cend(), isdigit);
    auto offset = distance(s.cbegin() ,opIter);
    
    

    //int a, b;
    auto a = stoi(s.substr(0, offset));
    auto b = stoi(s.substr(offset + 1));
    
    cout << s << " = " << Calc(a, b, *opIter) << endl;
    
}