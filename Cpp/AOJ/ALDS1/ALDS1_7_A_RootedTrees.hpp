#pragma once

#include <iostream>
#include <vector>
#include <string>

constexpr int nil {-1};

struct Node
{
    int id;
    int parent {-1};
    std::vector<int> children;

    int dimention() const
    {
        return children.size();
    }

    std::string childrenStr() const
    {
        using namespace std;
        string str = "[";
        for (int i = 0; i < children.size(); ++i)
        {
            str += to_string(children[i]);
            if (i + 1 != children.size())
                str += ", ";
        }
        str += "]";

        return str;
    }
};

std::istream& operator>>(std::istream& is, Node& node)
{
    using std::vector;

    int k;
    is >> node.id >> k;

    node.children = std::vector<int>(k);

    for (auto& c : node.children)
        is >> c;

    return is;
}

class Tree
{
public:

    Tree(int nodeNum)
        : nodes {std::vector<Node>(nodeNum)}
    {}

    void add(const Node& node)
    {
        nodes[node.id] = node;
    }

    void add(const Node&& node)
    {
        nodes[node.id] = std::move(node);
    }

    void calcParent()
    {
        for (const auto& n : nodes)
        {
            for (int c : n.children)
            {
                nodes[c].parent = n.id;
            }
        }
    }

    int depth(int id)
    {
        if (nodes[id].parent == nil)
            return 0;
        else
            return depth(nodes[id].parent) + 1;
    }

    std::string type(int id)
    {
        const auto& n = nodes[id];

        if (n.parent == nil)
            return "root";
        else if (n.dimention() == 0)
            return "leaf";
        else
            return "internal node";
    }
    
    void show(int id)
    {
        using namespace std;

        const auto& n = nodes[id];

        cout << "node " << n.id << ": parent = " << n.parent << ", depth = " <<
            depth(n.id) << ", " << type(n.id) << ", " << n.childrenStr() << endl;
    }

    void showAll()
    {
        for (const auto& n : nodes)
            show(n.id);
    }


private:

    std::vector<Node> nodes;
};

void solve();

void solve()
{
    using namespace std;

    int n;
    cin >> n;

    Tree tree {n};

    for (int i = 0; i < n; ++i)
    {
        Node node;
        cin >> node;
        tree.add(move(node));
    }

    tree.calcParent();

    tree.showAll();
}
