#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

constexpr int nil = -1;

class ILcs
{
public:
    using vvi = std::vector<std::vector<int>>;
    virtual int lcs() = 0;
    virtual int lcs(int i1, int i2) = 0;
};

class LcsLoop : public ILcs
{
public:

    LcsLoop(std::string str1, std::string str2)
        : str1 {" " + str1}
        , str2 {" " + str2}
        , dp {vvi(str1.size() + 1, std::vector<int>(str2.size() + 1))}
    {
        CalcLcs();
    }

    int lcs() override
    {
        return lcs(str1.size() - 1, str2.size() - 1);
    }

    int lcs(int i1, int i2) override
    {
        return dp[i1][i2];
    }

private:

    std::string str1;
    std::string str2;
    vvi         dp;
    
    void CalcLcs()
    {
        for (int i = 0; i < str1.size(); ++i)
            dp[i][0] = 0;
        for (int i = 0; i < str2.size(); ++i)
            dp[0][i] = 0;

        for (int i = 1; i < str1.size(); ++i)
        {
            for (int j = 1; j < str2.size(); ++j)
            {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
};

class LcsReccursion : public ILcs
{
public:
    LcsReccursion(const std::string& str1, const std::string& str2)
        : s1 {" " + str1}
        , s2 {" " + str2}
        , dp {vvi(s1.size(), std::vector<int>(s2.size(), nil))}
    {
        for (int i = 0; i < s1.size(); ++i)
            dp[i][0] = 0;
        for (int i = 0; i < s2.size(); ++i)
            dp[0][i] = 0;
    }

    int lcs() override
    {
        return lcs(s1.size() - 1, s2.size() - 1);
    }

    int lcs(int i1, int i2) override
    {
        if (dp[i1][i2] != nil)
            return dp[i1][i2];

        if (s1[i1] == s2[i2])
            return dp[i1 - 1][i2 - 1] + 1;
        
        dp[i1][i2] = std::max(lcs(i1 - 1, i2), lcs(i1, i2 - 1));
        return dp[i1][i2];
    }

private:

    std::string s1;
    std::string s2;
    vvi         dp;
};

void solve()
{
    using namespace std;

    int n;
    cin >> n;

    string s1, s2;

    for (int i = 0; i < n; ++i)
    {
        cin >> s1 >> s2;
        //LcsLoop lcs {s1, s2};
        LcsReccursion lcs {s1, s2};
        cout << lcs.lcs() << endl;
    }
}