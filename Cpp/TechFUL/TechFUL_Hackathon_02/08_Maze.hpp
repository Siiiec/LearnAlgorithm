#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
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

using ll = long long;

//vector
template <class T>
using vec = std::vector<T>;

struct Pos
{
    int x, y, d;
};

void solve()
{
    using namespace std;

    int N = 15;

    constexpr int goal = 3;
    constexpr int start = 5;

    vec<vec<int>> maze(1, vec<int>(N + 2, 1));

    Pos sPos, gPos;

    for (int i = 0; i < N; ++i)
    {
        string in;
        cin >> in;
        vec<int> line = {1};
        for (int j = 0; j < N; ++j)
        {
            auto subs = in.substr(j, 1);
            int cell;
            if (subs == "S")
            {
                cell = start;
                sPos = {j, i, 0};
            }
            else if (subs == "G")
            {
                cell = 0;
                gPos = {j, i, 0};
            }
            else
                cell = stoi(subs);
            line.push_back(cell);
        }
        line.push_back(1);

        maze.push_back(line);
    }

    maze.push_back(vec<int>(N + 2, 1));

    //-1‚Í–K‚ê‚Ä‚¢‚È‚¢‚Æ‚«
    vec<vec<int>> dist(N, vec<int>(N, -1));

    queue<Pos> qu;
    qu.push(sPos);

    while (!qu.empty())
    {
        auto pos = qu.front(); qu.pop();
        if (dist[pos.y][pos.x] == -1)
            dist[pos.y][pos.x] = pos.d;

        for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j)
            {
                if (i != 0 && j != 0)
                    continue;
                if (i == 0 && j == 0)
                    continue;
                if (maze[pos.y + 1 + i][pos.x + 1 + j] == 0 && dist[pos.y + i][pos.x + j] == -1)
                    qu.push({pos.x + j, pos.y + i, pos.d + 1});
            }

    }

    cout << dist[gPos.y][gPos.x] << endl;

}

//int main()
//{
//    solve();
//    return 0;
//}