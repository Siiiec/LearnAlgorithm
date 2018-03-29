#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <bitset>

constexpr int ElementNumMax {1000};
constexpr int ValueMax {10000};

//数値に対応したインデックスを保持
std::array<int, ValueMax> table;

class Cycle
{
public:
    
    static constexpr int nil = -1;

    void add(int x)
    {
        c.emplace_back(x);
        
        if (localMin == nil || x < localMin)
            localMin = x;
    }

    const std::vector<int>& cycle() const
    {
        return c;
    }

    int minValue() const
    {
        return localMin;
    }

    int minCost(int globalMin) const
    {
        if (c.size() == 1)
            return 0;

        int sum {std::accumulate(c.begin(), c.end(), 0)};
        return sum + 
            std::min(localMin + (c.size() + 1) * globalMin, (c.size() - 2) * localMin);
    }

private:

    std::vector<int>    c;
    int                 localMin = nil;
};

void solve();

void solve()
{
    using namespace std;

    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        //テーブルに数値のインデックスを記録
        table[vec[i]] = i;
    }

    sort(vec.begin(), vec.end());

    vector<Cycle> cycles;
    
    bitset<ElementNumMax> reached {};

    int globalMin {vec[0]};

    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] < globalMin)
            globalMin = vec[i];

        if (reached[i])
            continue;
        
        //サイクルを作成する
        Cycle c;
        c.add(vec[i]);

        int nextIndex = table[vec[i]];
        reached[i] = true;

        //1周するまで
        while (nextIndex != i)
        {
            c.add(vec[nextIndex]);
            reached[nextIndex] = true;
            nextIndex = table[vec[nextIndex]];
        }
        
        cycles.push_back(move(c));
    }

    int sum = accumulate(cycles.begin(), cycles.end(), 0, 
        [globalMin](int init, const Cycle& c)
    {
        return init + c.minCost(globalMin);
    });

    cout << sum << endl;
}