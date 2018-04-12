#include <iostream>
#include <queue>
#include <functional>
#include "AOJ\ALDS1\12_GraphII\B_SingleSourceShortestPathI.hpp"

#include <chrono>

using namespace std::chrono;

int main()
{
    auto begin = high_resolution_clock::now();

    solve();

    auto end = high_resolution_clock::now();

    auto time =  duration_cast<milliseconds>(end - begin);
    
    std::cout << time.count() << std::endl;

    return 0;

}