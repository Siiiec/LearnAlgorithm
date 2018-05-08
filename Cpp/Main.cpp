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

//��؂�p
void PrintLine() { std::cout << "---------------------------------" << std::endl; }

void PrintAll(std::vector<int> v)
{

    //�����o�֐��Ăяo��
    //.size()�ŗv�f���𓾂�
    int n = v.size();

    std::cout << "number of elements: " << n << std::endl;

    for (int i = 0; i < n; ++i)
        std::cout << v[i] << std::endl;

    std::cout << std::endl;
}

int main()
{
    //vector�̃f�t�H���g�\�z
    //����()�����Ȃ�
    //�v�f����0
    std::vector<int> v1;

    //�����ɗv�f��ǉ�
    //�����ɒǉ�����l��n��
    v1.push_back(1000000);

    //���e���m�F
    PrintAll(v1);

    //�v�f����ύX
    //�����͕ύX��̗v�f��
    //�ύX��̂ق����傫���ꍇ�̓f�t�H���g�l������
    v1.resize(5);

    //���e���m�F
    PrintAll(v1);


    //�f�t�H���g�\�z�ȊO�ɂ́A
    //�E�v�f�����w�肷�����
    //�E�v�f���A�����l���w�肷�����
    //�Ȃǂ�����
    
    using namespace std;

    //---------------------------------
    PrintLine();

    //�v�f�����w��
    //�v�f�̓f�t�H���g�̒l�ŏ����������
    vector<int> v2(2);
    PrintAll(v2);
    

    //---------------------------------
    PrintLine();

    //�v�f��4,�����l-1
    vector<int> v3(4, -1);
    PrintAll(v3);

    return 0;
}

//int main()
//{
//    solve();
//    return 0;
//}