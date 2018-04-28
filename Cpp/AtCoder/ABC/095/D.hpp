#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <utility>

using ll = long long;

template <class T>
using vec = std::vector<T>;

using pll = std::pair<ll, ll>;

constexpr ll nil = -1;
constexpr ll inf = std::numeric_limits<ll>::max();

template <class T>
struct Edge
{
    T to;
    T cost;

    bool operator<(const Edge& rhs) const
    {
        return cost < rhs.cost;
    }

    bool operator>(const Edge& rhs) const
    {
        return cost > rhs.cost;
    }
};

template <class T>
vec<ll> dijkstra(const vec<vec<Edge<T>>>& edges)
{
    using namespace std;



}

ll NormalizedPos(ll pos, ll c)
{
    while (pos < 0) pos += c;
    return pos % c;
}


pll LoopAccess(const vec<pll>& v, int i)
{
    while (i < 0) i += v.size();
    return v[i % v.size()];
}

void solve()
{
    using namespace std;
    int n;
    ll c;
    cin >> n >> c;

    vec<pll> e(n);
    for (auto& p : e) cin >> p.first >> p.second;

    vec<vec<pll>> edges(n + 1);

    edges[0].emplace_back(e[0]);
    edges[0].emplace_back(e[n - 1]);
    ll be = e[0].first + c - e[n - 1].first;
    edges[1].emplace_back(e[n - 1].first + c - e[0].first, e[0].second);
    edges[1].emplace_back(e[1].second - e[0].second, e[0].second);
    edges[n].emplace_back(e[n - 1].first + c - e[0].first, e[n - 1].second);
    edges[n].emplace_back(e[1].second - e[0].second, e[1].second);


    for (int i = 2; i < n; ++i)
    {
        edges[i].emplace_back(e[i].first - e[(i + 1) % n].first, c, e[i].second - e[(i + 1) % n].second);
        edges[i].emplace_back(e[i].first + e[(i + n  - 1) % n].first, e[i].second + e[(i + n - 1) % n].second);
    };


}