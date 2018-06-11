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

namespace {
    using ll = long long;
    using ull = unsigned long long;

    //vector
    template <class T>
    using vec = std::vector<T>;

    template <class T>
    using vv = vec<vec<T>>;

    constexpr std::size_t operator""_sz(ull n) { return std::size_t (n); }

    template <class T, class BinaryOperation>
    constexpr T foldr(std::initializer_list<T> args, T init, BinaryOperation op)
    {
        return std::accumulate(args.begin(), args.end(), init, op);
    }


#ifdef _MSVC_LANG
#pragma region Vector
#endif
    ///////////////////////////////////////////////////////////
    // Vector
    
    template <class T>
    struct Vec2D
    {
        T x, y;

        Vec2D() = default;

        constexpr Vec2D(T x, T y)
            : x {x}, y {y}
        {}

        static constexpr T Dot(const Vec2D& lhs, const Vec2D& rhs)
        {
            return lhs.x * rhs.x + lhs.y * rhs.y;
        }

        static constexpr T Cross(const Vec2D& lhs, const Vec2D& rhs)
        {
            return {lhs.x*rhs.y - lhs.y*rhs.x};
        }

        constexpr T dot(const Vec2D& rhs) const
        {
            Dot(*this, rhs);
        }

        constexpr Vec2D cross(const Vec2D& rhs) const
        {
            Dot(*this, rhs);
        }

        T magnitude() const
        {
            return std::sqrt(sqrMagnitude());
        }

        constexpr T sqrMagnitude() const
        {
            return x * x + y * y;
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

        constexpr bool isZero() const
        {
            return x == 0 && y == 0;
        }

        constexpr Vec2D operator+() const
        {
            return *this;
        }

        constexpr Vec2D operator-() const
        {
            return {-x, -y};
        }


        constexpr Vec2D operator+(Vec2D rhs) const
        {
            return {x + rhs.x, y + rhs.y};
        }

        constexpr Vec2D operator-(Vec2D rhs) const
        {
            return {x - rhs.x, y - rhs.y};
        }

        template <class U>
        constexpr Vec2D operator*(U rhs) const
        {
            return {x * rhs, y * rhs};
        }

        template <class U>
        constexpr Vec2D operator/(U rhs) const
        {
            return {x / rhs, y / rhs};
        }

        constexpr Vec2D& operator+=(const Vec2D& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        constexpr Vec2D& operator-=(const Vec2D& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        template <class U>
        constexpr Vec2D& operator*=(U s)
        {
            x *= s;
            y *= s;
            return *this;
        }

        template <class U>
        constexpr Vec2D& operator/=(U s)
        {
            x /= s;
            y /= s;
            return *this;
        }

    };

    template<class T, class U>
    inline constexpr Vec2D<T> operator*(U s, Vec2D<T> v)
    {
        return {s * v.x, s * v.y};
    }

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
    size_t hash(Args... args)
    {
        return foldr({static_cast<size_t>(args)...}, 0_sz,
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

        //int N, K;
        //cin >> N >> K;

        //vec<int> a(N);
        //for (auto& x : a)
        //    cin >> x;
        //
        //// dp[i + 1][j] 左からi番目まで使用してjが作れるか
        //vv<bool> dpl(N + 1, vec<bool>(K + 1, false));
        //// dp[i + 1][j] (a[i], a[N - 1]]まで使用してjが作れるか
        //vv<bool> dpr(N + 1, vec<bool>(K + 1, false));

        //for (int i = 0; i <= N; ++i)
        //{
        //    dpl[i][0] = true;
        //}

        //// 左からDP
        //for (int i = 0; i < N; ++i)
        //    for (int j = 0; j <= K; ++j)
        //    {
        //        dpl[i + 1][j] = dpl[i + 1][j] | dpl[i][j];
        //        if (j >= a[i])
        //            dpl[i + 1][j] = dpl[i + 1][j] | dpl[i][j - a[i]];
        //    }

        //for (int i = 0; i <= N; ++i)
        //{
        //    dpr[i][0] = true;
        //}

        //// 右からDP
        //for (int i = N; i > 0; --i)
        //    for (int j = 0; j <= K; ++j)
        //    {
        //        dpr[i - 1][j] = dpr[i - 1][j] | dpr[i][j];
        //        if (j >= a[i - 1])
        //            dpr[i - 1][j] = dpr[i - 1][j] | dpr[i][j - a[i - 1]];
        //    }

        //cout << ::hash(1, 3);

        //int no_needed {};

        Vec2D<double> x {1, 0};
        Vec2D<double> y {0, 1};

        auto xy = Vec2D<double>::Cross(x, y);


        auto printVec = [](Vec2D<double> v)
        {
            printAll({v.x, v.y}, " ");
            cout << endl;
        };

        printVec(x * 10);
        printVec(10 * x);

        printVec(x / 2.0);
        printVec(x - 4.0 * y);


    }
}

//int main()
//{
//    solve();
//    return 0;
//}