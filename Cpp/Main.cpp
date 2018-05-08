#include <iostream>
#include <queue>
#include <functional>
#include "AOJ\GRL\04_Path_Cycle\B_TopologicalSort.hpp"

#include <chrono>
#include <fstream>

#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

//区切り用
void PrintLine() { std::cout << "---------------------------------" << std::endl; }

void PrintAll(std::vector<int> v)
{

    //メンバ関数呼び出し
    //.size()で要素数を得る
    int n = v.size();

    std::cout << "number of elements: " << n << std::endl;

    for (int i = 0; i < n; ++i)
        std::cout << v[i] << std::endl;

    std::cout << std::endl;
}

int main()
{
    //vectorのデフォルト構築
    //後ろに()をつけない
    //要素数は0
    std::vector<int> v1;

    //末尾に要素を追加
    //引数に追加する値を渡す
    v1.push_back(1000000);

    //内容を確認
    PrintAll(v1);

    //要素数を変更
    //引数は変更後の要素数
    //変更後のほうが大きい場合はデフォルト値が入る
    v1.resize(5);

    //内容を確認
    PrintAll(v1);


    //デフォルト構築以外には、
    //・要素数を指定するもの
    //・要素数、初期値を指定するもの
    //などがある
    
    using namespace std;

    //---------------------------------
    PrintLine();

    //要素数を指定
    //要素はデフォルトの値で初期化される
    vector<int> v2(2);
    PrintAll(v2);
    

    //---------------------------------
    PrintLine();

    //要素数4,初期値-1
    vector<int> v3(4, -1);
    PrintAll(v3);

    return 0;
}

//int main()
//{
//    solve();
//    return 0;
//}