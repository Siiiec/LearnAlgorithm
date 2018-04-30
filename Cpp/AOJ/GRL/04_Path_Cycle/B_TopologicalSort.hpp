#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <queue>

using ll = long long;

template <class T>
using vec = std::vector<T>;

template <class T>
constexpr T nil = static_cast<T>(-1);

template <class T>
constexpr T inf = std::numeric_limits<T>::max() / 2;


constexpr int NIL = nil<int>;

void solve()
{
    using namespace std;

    int n, m;
    cin >> n >> m;

    vec<vec<int>> edges(n);
    vec<int> degIn(n, 0);

    for (int i = 0, from, to; i < m; ++i)
    {
        cin >> from >> to;
        edges[from].push_back(to);
        ++degIn[to];
    }

    vec<int> sortedV;
    queue<int> q;

    for (int i = 0; i < n; ++i)
        if (degIn[i] == 0)
            q.push(i);
    
    while (!q.empty())
    {
        auto v = q.front(); q.pop();

        sortedV.push_back(v);

        for (int e : edges[v])
            if (--degIn[e] == 0)
                q.push(e);
    }

    for (int v : sortedV)
        cout << v << endl;

}