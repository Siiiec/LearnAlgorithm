#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <valarray>
#include <utility>
#include <tuple>
#include <cmath>
#include <random>

using ll = long long;

//vector
template <class T>
using vec = std::vector<T>;

void solve()
{
    using namespace std;
    
    int N, M;
    cin >> N >> M;

    vec<int> roadNum(N);
    
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        ++roadNum[a - 1];
        ++roadNum[b - 1];
    }

    for (auto r : roadNum)
        cout << r << endl;
}

//int main()
//{
//    solve();
//    return 0;
//}