#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

constexpr int cardNum = 20;

enum class Range
{
    Lower,
    Between,
    Upper
};

Range InRange(int t, int min, int max)
{
    if (t < min)        return Range::Lower;
    else if (t > max)   return Range::Upper;
    else                return Range::Between;
}

bool Expectation(int current, const std::vector<bool>& remaining, int min, int max)
{
    int e {0};
    for (int i = 0; i < remaining.size(); ++i)
    {
        if (remaining[i])
        {
            if (InRange(current + i + 1, min, max) == Range::Between)
                ++e;
            else
                --e;
        }
    }

    return e >= 0;
}

void solve()
{
    using namespace std;

    int m, min, max;
    cin >> m;
    vector<bool> remaining(cardNum, true);
    vector<int> hand(m);

    for (auto& h : hand) cin >> h;
    cin >> min >> max;

    for (auto x : hand)
        remaining[x - 1] = false;

    int current = accumulate(hand.cbegin(), hand.cend(), 0);

    auto cond = InRange(current, min, max);

    if (cond == Range::Between)
        cout << "Stand!" << endl;
    else if (cond == Range::Upper)
        cout << "Error!" << endl;
    else
        cout << (Expectation(current, remaining, min, max) ? "Hit!" : "Surrender!") << endl;
    
}