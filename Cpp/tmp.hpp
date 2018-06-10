#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
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

// boost
#define USE_BOOST_IN_CODE
#ifdef USE_BOOST_IN_CODE
#include <boost\range.hpp>
#include <boost\range\algorithm.hpp>
#include <boost\range\numeric.hpp>
#include <boost\range\irange.hpp>
#include <boost\range\adaptor\strided.hpp>
#include <boost\range\adaptor\transformed.hpp>
#endif


using ll = long long;

//vector
template <class T>
using vec = std::vector<T>;

//namespace std
//{
//    template<>
//    class hash<Key>
//    {
//    public:
//        size_t operator() (const Key& key) const
//        {
//            size_t seed = 0;
//            auto i_hash = hash<int>()(key.i_th);
//            auto w_hash = hash<int>()(key.W);
//
//            seed ^= i_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//            seed ^= w_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//
//            return seed;
//        }
//    };
//}

void solve()
{
    using namespace std;

    vec<int> v {1, 2, 4, 5 ,6, 43, 4, 34, 1, 4, 7};

    boost::sort(v);

    auto iter = boost::sub_range<vec<int>>(begin(v) + 2, begin(v) + 5);

    boost::copy(iter, std::ostream_iterator<int>(std::cout, "\n"));

    boost::copy(
        boost::irange(0, 100)
        | boost::adaptors::strided(2)
        | boost::adaptors::transformed([](auto n) { return n * 2; })
        , std::ostream_iterator<int>(std::cout, " "));

}

//int main()
//{
//    solve();
//    return 0;
//}