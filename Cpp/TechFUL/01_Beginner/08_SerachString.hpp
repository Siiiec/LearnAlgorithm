#include <iostream>
#include <string>
#include <regex>
#include <numeric>
#include <algorithm>

void solve()
{
    using namespace std;
    string str, find;
    //cin >> str >> find;
    getline(cin, str);
    getline(cin, find);
    
    int count {};

    for (int i = 0, j = 0; i < str.size(); ++i)
    {
        bool matched {true};
        for (j = 0; j < find.size(); ++j)
        {
            if (i + j >= str.size() || str[i + j] != find[j])
            {
                matched = false;
                break;
            }
        }
        if (matched)
        {
            ++count;
            i += find.size() - 1;
        }
        
    }

    //regex re(find);
    //sregex_iterator iter(str.cbegin(), str.cend(), re);
    //std::sregex_iterator end;
    //int n = accumulate(iter, end, 0,
    //    [](int init, smatch m)
    //{
    //    return init + static_cast<int>(!m.empty());
    //});

    std::cout << "•¶Žš—ñ : " << str << endl;
    std::cout << "ŒŸõ•¶Žš—ñ : " << find << endl;
    std::cout << find << "‚ÌoŒ»‰ñ” : " << count << "‰ñ" << endl;

}