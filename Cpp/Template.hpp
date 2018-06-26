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
#include <memory>
#include <random>
#include <fstream>

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


///////////////////////////////////////////////////////////
// Vector

template <class T>
struct Vec2D
{
    T x, y;

    Vec2D() = default;

    Vec2D(T x, T y)
        : x {x}, y {y}
    {}

    static T Dot(Vec2D lhs, Vec2D rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    static double Cross(Vec2D lhs, Vec2D rhs)
    {
        return {
            lhs.x*rhs.y - lhs.y*rhs.x
        };
    }

    T magnitude() const
    {
        return std::sqrt(sqrMagnitude());
    }

    T sqrMagnitude() const
    {
        return x * x + y * y;
    }

    Vec2D normalized() const
    {
        return *this / magnitude();
    }

    Vec2D normalize()
    {
        return *this = normalized();;
    }

    template <class U>
    Vec2D operator*(U lhs) const
    {
        return Vec2D(x * lhs, y * lhs);
    }

    template <class U>
    Vec2D operator/(U lhs) const
    {
        return Vec2D(x / lhs, y / lhs);
    }
};

template<class T, class U>
inline Vec2D<T> operator*(U rhs, Vec2D<T> v)
{
    return {rhs * v.x, rhs * v.y};
}

template <class T>
struct Vec2D
{
    T x, y, z;

    Vec2D() = default;

    Vec2D(T x, T y, T z)
        : x {x}, y {y}, z {z}
    {}

    Vec2D(T x, T y)
        : Vec2D(x, y, 0)
    {}

    static T Dot(Vec2D lhs, Vec2D rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    static Vec2D Cross(Vec2D lhs, Vec2D rhs)
    {
        return {
            lhs.y*rhs.z - lhs.z*rhs.y,
            lhs.z*rhs.x - lhs.x*rhs.z,
            lhs.x*rhs.y - lhs.y*rhs.x
        };
    }

    T magnitude() const
    {
        return std::sqrt(sqrMagnitude());
    }

    T sqrMagnitude() const
    {
        return x * x + y * y + z * z;
    }

    Vec2D normalized() const
    {
        return *this / magnitude();
    }

    Vec2D normalize()
    {
        *this = normalized();
        return *this;
    }

    template <class U>
    Vec2D operator*(U lhs) const
    {
        return Vec2D(x * lhs, y * lhs, z * lhs);
    }

    template <class U>
    Vec2D operator/(U lhs) const
    {
        return Vec2D(x / lhs, y / lhs, z / lhs);
    }
};

template<class T, class U>
inline Vec2D<T> operator*(U rhs, Vec2D<T> v)
{
    return {rhs * v.x, rhs * v.y, rhs * v.z};
}

// Vector
///////////////////////////////////////////////////////////

// args‚©‚ç
template <class... Args>
size_t hash(Args... args)
{
    return fold({static_cast<size_t>(args)...}, 0_sz,
        [](auto seed, auto x)
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

void solve()
{
    using namespace std;
    
}

//int main()
//{
//    solve();
//    return 0;
//}