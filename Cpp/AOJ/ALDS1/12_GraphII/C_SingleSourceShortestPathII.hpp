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

    while (true)
    {
        //�n�_����̍ŒZ�_�A�R�X�g
        Edge d {nil, inf};

        //��ԋ߂��_��T��
        while (!pqDist.empty())
        {
            auto e = pqDist.top();
            pqDist.pop();

            if (!reached[e.to])
            {
                d = e;
                break;
            }
        }

        if (d.cost == inf)
            break;

        reached[d.to] = true;
        distances[d.to] = d.cost;

        for (auto& e : edges[d.to])
        {
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

    //�אڃ��X�g�`��
    vec<vec<Edge>> edges(n);

    //����
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