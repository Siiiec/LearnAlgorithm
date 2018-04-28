#include <iostream>
#include <queue>
#include <functional>
#include "TechFUL\TechFUL_Hackathon_01\06.hpp"

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
    namespace C //入れ子にもできる
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