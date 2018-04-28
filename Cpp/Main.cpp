#include <iostream>
#include <queue>
#include <functional>
#include "TechFUL\02_Intermediate\07_stack.hpp"

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
    A::func();      //A::func()
    B::C::func();   //B::C::func()
    A::hoge();      //A::func()
    B::C::hoge();   //A::func()
}