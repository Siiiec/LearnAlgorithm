#include <iostream>
#include <string>

void solve()
{
    using namespace std;
    string source, find, replace;
    getline(cin, source);
    getline(cin, find);
    getline(cin, replace);

    string out = "";

    for (int i = 0; i < source.size(); ++i)
    {
        if (source.substr(i, find.size()) == find)
        {
            out += replace;
            i += find.size() - 1;
        }
        else
        {
            out += source[i];
        }
    }

    cout << out << endl;
}