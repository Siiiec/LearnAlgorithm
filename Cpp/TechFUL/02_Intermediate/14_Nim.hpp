#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>

template <class T>
using vec = std::vector<T>;
using bit = std::bitset<7>;


void solve()
{
    using namespace std;

    vec<bit> stones(3);
    for (auto& stone : stones)
    {
        unsigned in;
        cin >> in;
        stone = {in};
    }

    bit b = accumulate(stones.cbegin(), stones.cend(), bit {},
        [](bit init, bit b){
            return init ^ b;
        });
    
    if (b.none())
    {
        cout << "‰ð‚È‚µ" << endl;
    }

    for (int i = 0; i < 3; ++i)
    {
        auto remove = stones[i] ^ b;
        if (remove.none())
            cout << i << "   " << b.to_ulong() << endl;
    }
}