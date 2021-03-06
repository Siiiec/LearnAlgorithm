#pragma once

#include <iostream>
#include <future>
#include <thread>

int foo()
{
    std::cout << "executes foo()\n";
    return 3;
}

void solve()
{
    using namespace std;
    {
        cout << "invokes" << endl;
        auto f = async(launch::async, foo);
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << "main thread slept for 10 msec\n";
        //結果を取得
        auto result = f.get();
        cout << "foo()=" << result << endl;
    }

    cout << endl;

    //遅延実行
    {
        //fooはまだ実行しない
        cout << "invokdes" << endl;
        auto f = async(launch::deferred, foo);
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << "main thread slept for 10 msec\n";
        //ここでfoo()が実行される
        auto result = f.get();
        cout << "foo()=" << result << endl;
    }
}