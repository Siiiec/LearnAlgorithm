#include <iostream>
#include <queue>
#include <functional>
#include "AtCoder\AGC\023\A.hpp"

#include <chrono>
#include <fstream>

namespace A
{
    void func() { std::cout << "A::func()" << std::endl; }
    void hoge()
    {
        func();
    }
}

namespace B
{
    namespace C //“ü‚êŽq‚É‚à‚Å‚«‚é
    {
        void func() { std::cout << "B::C::func()" << std::endl; }
        void hoge()
        {
            A::hoge();
        }
    }
}

int main()
{
    solve();
    return 0;
}