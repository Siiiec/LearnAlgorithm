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

    auto pow = [](int x, int y)
    {
        int ans = 1;
        for (; y > 0; --y)
            ans *= x;
        return ans;
    };

    // id: i, k ラウンドで当たる人の半開区間
    std::pair<int, int> scope(int i, int k)
    {
        int range = pow(2, k - 1);
        int block = i / range;

        if (block % 2 == 0)
        {
            return {range * (block + 1), range * (block + 2)};
        }
        else
        {
            return {range * (block - 1), range * block};
        }
    }

    long double P(int rate1, int rate2)
    {
        return 1.0 / (1 + std::pow(10.0l, (rate2 - rate1) / 400.0l));
    }

    void solve()
    {
        using namespace std;
        
        int K;
        cin >> K;

        vec<int> r(pow(2, K));
        for (auto& x : r)
            cin >> x;

        // dp[i][j]: 人iが第jラウンドで勝つ確率
        vv<long double> dp(r.size(), vec<long double>(K + 1, 0));

        for (int i = 0; i < r.size(); ++i)
            dp[i][0] = 1.0;

        for (int j = 1; j <= K; ++j)
            for (int i = 0; i < r.size(); ++i)
            {
                long double winP = 0.0;
                auto range = scope(i, j);
                for (int x = range.first; x < range.second; ++x)
                    winP += P(r[i], r[x]) * dp[x][j - 1];
                dp[i][j] = dp[i][j - 1] * winP;
            }

        for (int i = 0; i < r.size(); ++i)
            cout << fixed << setprecision(9) << dp[i][K] << endl;
    }
}

//int main()
//{
//    solve();
//    return 0;
//}