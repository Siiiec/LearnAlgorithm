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

//vector
template <class T>
using vec = std::vector<T>;

template <class T>
using vv = vec<vec<T>>;

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
struct Vec3D
{
    T x, y, z;

    Vec3D() = default;

    Vec3D(T x, T y, T z)
        : x {x}, y {y}, z {z}
    {}

    Vec3D(T x, T y)
        : Vec3D(x, y, 0)
    {}

    static T Dot(Vec3D lhs, Vec3D rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    static Vec3D Cross(Vec3D lhs, Vec3D rhs)
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

    Vec3D normalized() const
    {
        return *this / magnitude();
    }

    Vec3D normalize()
    {
        *this = normalized();
        return *this;
    }

    template <class U>
    Vec3D operator*(U lhs) const
    {
        return Vec3D(x * lhs, y * lhs, z * lhs);
    }

    template <class U>
    Vec3D operator/(U lhs) const
    {
        return Vec3D(x / lhs, y / lhs, z / lhs);
    }
};

template<class T, class U>
inline Vec3D<T> operator*(U rhs, Vec3D<T> v)
{
    return {rhs * v.x, rhs * v.y, rhs * v.z};
}


//template<int... keys>
//struct hash
//{
//    size_t operator() (Keys... keys) const
//    {
//        size_t seed = 0;
//        auto i_hash = hash<int>()(key.i_th);
//        auto w_hash = hash<int>()(key.W);
//
//        seed ^= i_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//        seed ^= w_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//
//        return seed;
//    }
//};


void solve()
{
    using namespace std;
    int n;

    while (cin >> n)
    {
        if (n == 0)
            break;

        
    }

}

//int main()
//{
//    solve();
//    return 0;
//}