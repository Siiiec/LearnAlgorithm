#include <cmath>

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
