#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <queue>
#include <shared_mutex>
#include <iomanip>
#include <atomic>
#include <bitset>


std::mutex printMtx;
void printValue(int x)
{
    std::lock_guard<std::mutex> lock(printMtx);
    std::cout << "id: " << std::setw(8) << std::this_thread::get_id()
        << "value: " << std::setw(8) << x << std::endl;
}

class X
{
public:

    void writer(int i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        qu.push(i);
    }

    void reader()
    {
        int x = -1;
        {
            //所有権を取得できるまでブロック
            std::lock_guard<std::mutex> lock(mtx);
            if (!qu.empty())
            {
                x = qu.front();
                qu.pop();
            }
        }
        if (x != -1)
            printValue(x);
    }

private:

    std::mutex mtx;
    std::queue<int> qu;
};

X obj;

template <class Rep, class Period>
void HeavyOperation(const std::chrono::duration<Rep, Period>& time)
{
    using namespace std;
    this_thread::sleep_for(time);
}

void writerThread()
{
    for (int i = 0; i < 30; ++i)
    {
        HeavyOperation(std::chrono::milliseconds(500));
        obj.writer(i);
    }
}

void readerThread()
{
    for (int i = 0; i < 10; ++i)
    {
        HeavyOperation(std::chrono::milliseconds(500));
        obj.reader();
    }
}

void solve()
{
    using namespace std;
    
    thread writer1(writerThread);
    thread reader1(readerThread);
    thread reader2(readerThread);
    thread reader3(readerThread);


    //for (int i = 0; i < 30; ++i)
    //{
    //    HeavyOperation(std::chrono::milliseconds(500));
    //    cout << i << endl;
    //}

    writer1.join();
    reader1.join();
    reader2.join();
    reader3.join();
}