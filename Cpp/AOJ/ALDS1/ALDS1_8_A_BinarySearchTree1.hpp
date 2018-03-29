#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>

template <class T>
using sp = std::shared_ptr<T>;

struct Node
{
    explicit Node(int key)
        : key {key}
    {}

    int key;
    sp<Node> parent    {nullptr};
    sp<Node> left       {nullptr};
    sp<Node> right      {nullptr};
};

class BinarySearchTree
{
public:

    void insert(int key)
    {
        auto z = std::make_shared<Node>(key);
        //x‚Ìe‚ğ•Û
        sp<Node> y {nullptr};
        auto x {root};

        while (x != nullptr)
        {
            //e‚ğ•Û
            y = x;
            if (key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;

        if (y == nullptr)           root = z;
        else if (z->key < y->key)   y->left = z;
        else                        y->right = z;
    }

    void printInorder()
    {
        printInorder(root);
    }

    void printPreorder()
    {
        printPreorder(root);
    }

private:

    sp<Node> root {nullptr};

    void printInorder(sp<Node> c)
    {
        if (c == nullptr)
            return;
        
        printInorder(c->left);
        std::cout << " " << c->key;
        printInorder(c->right);
    }

    void printPreorder(sp<Node> c)
    {
        if (c == nullptr)
            return;

        std::cout << " " << c->key;
        printPreorder(c->left);
        printPreorder(c->right);
    }
};

void solve();

void solve()
{
    using namespace std;
    
    int n;
    cin >> n;
    BinarySearchTree tree;

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;


        if (s == "insert")
        {
            int key;
            cin >> key;
            tree.insert(key);
        }
        else
        {
            tree.printInorder();
            cout << endl;
            tree.printPreorder();
            cout << endl;
        }
    }


}