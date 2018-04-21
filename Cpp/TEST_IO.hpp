#include <iostream>
#include <vector>

struct TEST
{
    int i;

    int getI()
    {
        return i;
    }
};

namespace namae
{

}

void solve()
{
    using namespace std;


    int num;
    cin >> num;


    vector<int> v(num);
    //vector<vector<int>> v(num ,vector<int>(num));

    

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++i)
        {
            cout << i << ', ' << j << ": " << v[i][j];
        }

    }
}


