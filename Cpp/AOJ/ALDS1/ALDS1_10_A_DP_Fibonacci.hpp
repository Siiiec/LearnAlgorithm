#pragma once

#include <iostream>

constexpr int N = 45;

int Fib_loop(int n)
{
    int dp[N] {};

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < N; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int Fib_Reccursion(int n)
{
    constexpr int nil {};
    static int dp[N] {};

    if (n <= 1 && dp[n] == nil)
        dp[n] = 1;
    else if (dp[n] == nil)
    {
        dp[n] = Fib_Reccursion(n - 1) + Fib_Reccursion(n - 2);
    }

    return dp[n];
}

void solve()
{
    int n;
    std::cin >> n;
    std::cout << Fib_Reccursion(n) << std::endl;
}