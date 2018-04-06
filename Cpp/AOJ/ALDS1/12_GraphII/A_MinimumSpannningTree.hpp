#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <functional>

template <class T>
using vec = std::vector<T>;

constexpr int nil = -1;

struct Edge
{
    int to;
    int weight;
};

struct EdgeTwoWay
{
    int e1;
    int e2;
    int weight;

    bool operator<(const EdgeTwoWay& rhs)
    {
        return weight < rhs.weight;
    }
};

class WeightedGraph
{
public:

    explicit WeightedGraph(int n)
        : edges(n)
    {}

    void connect(int from, int to, int weight)
    {
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    int prim()
    {
        using namespace std;
        priority_queue<EdgeTwoWay, vector<EdgeTwoWay>, greater<EdgeTwoWay>> qu;
        vector<bool> reached(edges.size());
        
        
    }

    //void sort()
    //{
    //    for (auto& e : edges)
    //    {
    //        std::sort(e.begin(), e.end(), [](Edge e1, Edge e2)
    //        {
    //            return e1.to < e2.to;
    //        });
    //    }
    //}

private:

    vec<vec<Edge>> edges;
};

void solve()
{
    using namespace std;
    int n;
    cin >> n;
    
    WeightedGraph wg(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0, in; j < n; ++j)
        {
            cin >> in;
            if (in != nil)
                wg.connect(i, j, in);
        }
    }
}