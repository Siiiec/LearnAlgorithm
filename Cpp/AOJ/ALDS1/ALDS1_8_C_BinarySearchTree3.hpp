#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>

template <class T>
using sp = std::shared_ptr<T>;

template <class T>
using wp = std::weak_ptr<T>;

struct Node
{
    explicit Node(int key)
        : key {key}
    {}

    int key;
    wp<Node> parent;
    sp<Node> left {nullptr};
    sp<Node> right {nullptr};
};

class BinarySearchTree
{
public:

    void insert(int key)
    {
        auto z = std::make_shared<Node>(key);
        //xÇÃêeÇï€éù
        sp<Node> y {nullptr};
        auto x {root};

        while (x != nullptr)
        {
            //êeÇï€éù
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

    sp<Node> find(int key)
    {
        return find(key, root);
    }

    void erase(int key)
    {
        auto n = find(key);
        if (n == nullptr)
            return;
        erase(n);
    }

    void eraseAll()
    {

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

    sp<Node> find(int key, sp<Node> n)
    {
        if (n == nullptr)
            return n;
        if (key == n->key)
            return n;
        else if (key < n->key)
            return find(key, n->left);
        else
            return find(key, n->right);
    }

    void erase(sp<Node> n)
    {
        if (n == nullptr)
            return;

        auto p = n->parent.lock();
        auto count = childCount(n);
        if (count == 0)
        {
            if (p->left == n)       p->left = nullptr;
            else if(p->right == n)  p->right = nullptr;
        }
        else if (count == 1)
        {
            sp<Node> child;
            if (n->left == nullptr) child = n->right;
            else                    child = n->left;
            child->parent = p;
            if (p->left == n)   p->left = child;
            else                p->right = child;
        }
        else if (count == 2)
        {
            auto next = getMinimum(n->right);
            n->key = next->key;
            erase(next);
        }
        n = nullptr;
    }

    int childCount(sp<Node> n)
    {
        return (n->left != nullptr ? 1 : 0) + (n->right != nullptr ? 1 : 0);
    }

    sp<Node> getMinimum(sp<Node> n)
    {
        auto x {n};
        while (x->left != nullptr)
            x = x->left;
        return x;
    }

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

        int key;
        if (s == "insert")
        {
            cin >> key;
            tree.insert(key);
        }
        else if (s == "find")
        {
            cin >> key;
            cout << (tree.find(key) != nullptr ? "yes" : "no") << endl;
        }
        else if(s == "print")
        {
            tree.printInorder();
            cout << endl;
            tree.printPreorder();
            cout << endl;
        }
        else if (s == "delete")
        {
            cin >> key;
            tree.erase(key);
        }
    }
}