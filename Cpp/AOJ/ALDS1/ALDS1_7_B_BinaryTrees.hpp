#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

constexpr int nil = -1;

struct Node
{
    int id;
    int parent {nil};
    int left {nil};
    int right {nil};

    int degree() const
    {
        return (left != nil ? 1 : 0) + (right != nil ? 1 : 0);
    }

    std::string type() const
    {
        if (parent == nil)
            return "root";
        else if (left == nil && right == nil)
            return "leaf";
        else
            return "internal node";
    }
};

std::istream& operator>>(std::istream& is, Node& node)
{
    is >> node.id >> node.left >> node.right;
    return is;
}

class Tree
{
public:
    virtual void add(const Node& node) = 0;
    virtual void show(int id) = 0;
    virtual void showAll() = 0;
};

class BinaryTree : public Tree
{
public:

    BinaryTree(int n)
        : nodes {std::vector<Node>(n)}
        , depths {std::vector<int>(n)}
        , heights {std::vector<int>(n)}
    {}

    void add(const Node& node) override
    {
        int p;
        p = nodes[node.id].parent;
        nodes[node.id] = node;

        setParent(node.id, p);
        setParent(node.left, node.id);
        setParent(node.right, node.id);
    }

    void show(int id) override
    {
        using namespace std;
        const auto& n = nodes[id];

        cout << "node " << id << ": parent = " << n.parent << ", sibling = "
            << sibling(id) << ", degree = " << n.degree() << ", depth = " << depths[id]
            << ", height = " << height(id) << ", " << n.type() << endl;
    }

    void showAll() override
    {
        for (int i = 0; i < nodes.size(); ++i)
            show(i);
    }

    void setDepth()
    {
        setDepth(root(), 0);
    }

    void setParent(int id, int parent)
    {
        if (id == nil)
            return;
        nodes[id].parent = parent;
    }

    void setDepth(int id, int depth)
    {
        if (id == nil)
            return;

        depths[id] = depth++;
        setDepth(nodes[id].left, depth);
        setDepth(nodes[id].right, depth);
    }

    int height(int id)
    {
        if (id == nil)
            return -1;

        const auto& n = nodes[id];
        return std::max(height(n.left), height(n.right)) + 1;
    }

    int sibling(int id)
    {
        const auto& n = nodes[id];
        if (n.parent == nil)
            return nil;
        else if (nodes[n.parent].right != id && nodes[n.parent].left != id)
            return nil;
        else if (nodes[n.parent].right == id)
            return nodes[n.parent].left;
        else
            return nodes[n.parent].right;
    }

    int root()
    {
        int id {0};
        while (true)
        {
            if (nodes[id].parent == nil)
                break;
            else
                id = nodes[id].parent;
        }

        return id;
    }

private:

    std::vector<Node> nodes;
    std::vector<int> depths;
    std::vector<int> heights;
};

void solve();

void solve()
{
    using namespace std;
    int n;
    cin >> n;
    BinaryTree tree(n);

    for (int i = 0; i < n; ++i)
    {
        Node node;
        cin >> node;
        tree.add(node);
    }

    tree.setDepth();
    tree.showAll();
}