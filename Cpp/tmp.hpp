#include <cstddef>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <limits>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <valarray>
#include <utility>
#include <tuple>
#include <cmath>
#include <memory>
#include <random>
#include <fstream>
#include <locale>

#if (__cplusplus >= 201703L)
#include <filesystem>
namespace fs = std::filesystem;
#endif

// boost
//#define USE_BOOST_IN_CODE
#ifdef USE_BOOST_IN_CODE
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/strided.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/format.hpp>
#endif 

namespace
{

    using ll = long long;
    using ull = unsigned long long;

    //vector
    template <class T>
    using vec = std::vector<T>;

    template <class T>
    using vv = vec<vec<T>>;

    constexpr std::size_t operator""_sz(ull n) { return std::size_t(n); }

    template <class T, class BinaryOperation>
    constexpr T fold(std::initializer_list<T> args, T init, BinaryOperation op)
    {
        return std::accumulate(args.begin(), args.end(), init, op);
    }

    // numeric_low
    namespace numeric
    {
        template<typename T>
        constexpr bool isOdd(T x)
        {
            return x % 2 != 0;
        }

        template<typename T>
        constexpr bool isEven(T x)
        {
            return x % 2 == 0;
        }

        // 最大公約数
        template<class T>
        constexpr T gcd(const T x, const T y)
        {
            if (x < 0)return gcd(-x, y);
            if (y < 0)return gcd(x, -y);
            return (!y) ? x : gcd(y, x % y);
        }

        // 最小公倍数
        template<class T>
        constexpr T lcm(const T x, const T y)
        {
            if (x < 0)return lcm(-x, y);
            if (y < 0)return lcm(x, -y);
            return x * (y / gcd(x, y));
        }

        // 素数判定
        template<class T>
        constexpr bool isPrime(const T x)
        {
            if (x <= 1)return false;
            for (T i = 2; i * i <= x; ++i)
                if (x % i == 0)
                    return false;
            return true;
        }
    }

    // ビット演算
    namespace bitOp
    {

        template <int N>
        constexpr std::size_t distanceBetween(const std::bitset<N> bit, std::size_t current, bool isNext = true)
        {
            if (current > N || current < 0)
                return -1;
            const int dir = isNext ? 1 : -1;
            for (auto i = current + dir; i >= 0 && i < N; i += dir)
                if (bit[i])
                    return (i - current) * dir;
            return -1;
        }

        // 次の立っているビットまでの距離
        template <int N>
        constexpr std::size_t distanceBetweenNext(const std::bitset<N> bit, std::size_t current)
        {
            return distanceBetween(bit, current, true);
        }

        // 前の立っているビットまでの距離
        template <int N>
        constexpr std::size_t distanceBetweenPrev(const std::bitset<N> bit, std::size_t current)
        {
            return distanceBetween(bit, current, false);
        }
    }

    // argsからハッシュ値を作成
    template <class... Args>
    std::size_t hash(Args... args)
    {
        return fold({static_cast<std::size_t>(args)...}, 0_sz,
            [](std::size_t seed, std::size_t x)
        {
            // uses magic number from boost
            return seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        });
    }

    template <class Begin, class End>
    void printAll(Begin beginIter, End endIter, std::string delimiter)
    {
        for (auto iter {beginIter}; iter != endIter; ++iter)
        {
            std::cout << *iter;
            if (std::distance(iter, endIter) != 1)
                std::cout << delimiter;
        }
    }

    template <class Container>
    void printAll(const Container& c, std::string delimiter)
    {
        printAll(std::cbegin(c), std::cend(c), delimiter);
    }

    template<class T>
    void printAll(const std::initializer_list<T>& ini, std::string delimiter)
    {
        printAll(ini.begin(), ini.end(), delimiter);
    }

    using ld = long double;

    template <class T>
    constexpr T nil = static_cast<T>(-1);
        
    void solve()
    {
        using namespace std;

        vec<string> lines;



        
    }
}

//int main()
//{
//    solve();
//    return 0;
//}