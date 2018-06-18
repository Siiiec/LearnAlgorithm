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

    //template <class Container>
    //std::istream& operator>>(std::istream& is, Container& c)
    //{
    //    const auto end = std::cend(c);
    //    for (auto iter = std::cbegin(c); iter != end; ++iter)
    //        is >> *iter;
    //    return is;
    //}

    template <class T, class BinaryOperation>
    constexpr T fold(std::initializer_list<T> args, T init, BinaryOperation op)
    {
        return std::accumulate(args.begin(), args.end(), init, op);
    }


#ifdef _MSVC_LANG
#pragma region Vector
#endif
    ///////////////////////////////////////////////////////////
    // Vector

    template <class T>
    struct Vec3D
    {
        T x, y, z;

        Vec3D() = default;

        constexpr Vec3D(T x, T y, T z)
            : x {x}, y {y}, z {z}
        {}

        constexpr Vec3D(T x, T y)
            : Vec3D(x, y, 0)
        {}

        static constexpr T Dot(const Vec3D& lhs, const Vec3D& rhs)
        {
            return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
        }

        static constexpr Vec3D Cross(const Vec3D& lhs, const Vec3D& rhs)
        {
            return {
                lhs.y*rhs.z - lhs.z*rhs.y,
                lhs.z*rhs.x - lhs.x*rhs.z,
                lhs.x*rhs.y - lhs.y*rhs.x
            };
        }

        constexpr T dot(const Vec3D& rhs) const
        {
            Dot(*this, rhs);
        }

        constexpr Vec3D cross(const Vec3D& rhs) const
        {
            Dot(*this, rhs);
        }

        T magnitude() const
        {
            return std::sqrt(sqrMagnitude());
        }

        constexpr T sqrMagnitude() const
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

        constexpr bool isZero() const
        {
            return x == 0 && y == 0 && z == 0;
        }

        constexpr Vec3D operator+() const
        {
            return *this;
        }

        constexpr Vec3D operator-() const
        {
            return {-x, -y, -z};
        }


        constexpr Vec3D operator+(Vec3D rhs) const
        {
            return {x + rhs.x, y + rhs.y, z + rhs.z};
        }

        constexpr Vec3D operator-(Vec3D rhs) const
        {
            return {x - rhs.x, y - rhs.y, z - rhs.z};
        }

        template <class U>
        constexpr Vec3D operator*(U rhs) const
        {
            return {x * rhs, y * rhs, z * rhs};
        }

        template <class U>
        constexpr Vec3D operator/(U rhs) const
        {
            return {x / rhs, y / rhs, z / rhs};
        }

        constexpr Vec3D& operator+=(const Vec3D& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        constexpr Vec3D& operator-=(const Vec3D& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        template <class U>
        constexpr Vec3D& operator*=(U s)
        {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }

        template <class U>
        constexpr Vec3D& operator/=(U s)
        {
            x /= s;
            y /= s;
            z /= s;
            return *this;
        }

    };

    template<class T, class U>
    inline constexpr Vec3D<T> operator*(U s, Vec3D<T> v)
    {
        return {s * v.x, s * v.y, s * v.z};
    }

    // Vector
    ///////////////////////////////////////////////////////////
#ifdef _MSVC_LANG
#pragma endregion Vector
#endif

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

    void solve()
    {
        using namespace std;

        ll n, m;
        cin >> n >> m;
        array<priority_queue<ll>, 8> pq;

        for (int i = 0; i < n; ++i)
        {
            ll x, y, z;
            cin >> x >> y >> z;

            int index {};
            for (int ix = -1; ix <= 1; ix += 2)
                for (int iy = -1; iy <= 1; iy += 2)
                    for (int iz = -1; iz <= 1; iz += 2)
                    {
                        pq[index++].emplace(x * ix + y * iy + z * iz);
                    }
        }

        array<ll, 8> sum {};

        for (int i = 0; i < 8; ++i)
            for (int mIndex = 0; mIndex < m; ++mIndex)
            {
                sum[i] += pq[i].top(); pq[i].pop();
            }

        cout << accumulate(sum.cbegin(), sum.cend(), 0ll,
            [](ll init, ll x)
            {
                return max(init, x);
            })
            << endl;
    }
}

//int main()
//{
//    solve();
//    return 0;
//}