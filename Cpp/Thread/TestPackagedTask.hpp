#pragma once

#include <iostream>
#include <future>
#include <stdexcept>
#include <utility>

int foo(bool notThrow)
{
    if (notThrow)
    {
        return 3;
    }
    else
    {
        throw std::runtime_error("foo() threw runtime_error");
    }
}

void solve()
{
    using namespace std;

    try
    {
        packaged_task<int(bool)> task(foo);
        task(false);
        cout << task.get_future().get() << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    
}