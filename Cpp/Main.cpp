#include <iostream>
#include <queue>
#include <functional>
#include "AOJ\ALDS1\12_GraphII\C_SingleSourceShortestPathII.hpp"

#include <chrono>
#include <fstream>

using namespace std::chrono;
using namespace std;

int main()
{
    ifstream in(string(R"(C:\Users\ca39g\Documents\Visual Studio 2017\Projects\LearnAlgorithm\Release\03.txt)"));
    cin.rdbuf(in.rdbuf());

    auto begin = high_resolution_clock::now();

    solve();

    auto end = high_resolution_clock::now();

    auto time =  duration_cast<milliseconds>(end - begin);
    
    std::cout << time.count() << std::endl;

    return 0;

}