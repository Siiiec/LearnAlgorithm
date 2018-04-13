#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <functional>
#include <numeric>
#include <limits>

template <class T>
using vec = std::vector<T>;

constexpr int nil = -1;
constexpr int inf = std::numeric_limits<int>::max();

struct Edge
{
    int to;
    int cost;

    bool operator<(const Edge& rhs) const
    {
        return cost < rhs.cost;
    }

    bool operator>(const Edge& rhs) const
    {
        return cost > rhs.cost;
    }
};



vec<int> dijkstra(const vec<vec<Edge>>& edges)
{
    using namespace std;

    const int n = edges.size();
    vec<int> distances(n, inf);
    vec<bool> reached(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pqDist;

    pqDist.push({0, 0});


    while (!pqDist.empty())
    {
        //始点からの最短点、コスト
        auto d = pqDist.top();
        pqDist.pop();

        //探索済みならスキップ
        if (reached[d.to])
            continue;

        reached[d.to] = true;
        distances[d.to] = d.cost;

        for (auto& e : edges[d.to])
        {
            //未探査の候補を追加
            if (!reached[e.to])
                pqDist.push({e.to, d.cost + e.cost});
        }
    }
    
    return distances;
}

void solve()
{
    using namespace std;
    int n;
    cin >> n;

    //隣接リスト形式
    vec<vec<Edge>> edges(n);

    //入力
    for (int i = 0; i < n; ++i)
    {
        int v, k;
        cin >> v >> k;
        for (int j = 0; j < k; ++j)
        {
            int to, cost;
            cin >> to >> cost;
            edges[i].push_back({to, cost});
        }
    }

    auto d = dijkstra(edges);

    for (int i = 0; i < n; ++i)
    {
        cout << i << " " << d[i] << endl;
    }
}